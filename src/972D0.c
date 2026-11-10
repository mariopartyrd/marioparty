/* libultra audio/env.c + audio/reverb.c (2.0I), one unit here. The static tables (eqpower,
   L_INC) live in the data asm. */
#define alEnvmixerPull func_800966D0
#define _pullSubFrame func_80096CA4
#define _frexpf func_80096F78
#define _ldexpf func_80097058
#define _getRate func_8009707C
#define _getVol func_800972FC
#define alFxPull func_80097380
#define alFxParam func_800976F4
#define alFxParamHdl func_80097708
#define _loadOutputBuffer func_800978F8
#define _loadBuffer func_80097B10
#define _saveBuffer func_80097C80
#define _filterBuffer func_80097DF0
#define _doModFunc func_80097E8C
#define _init_lpfilter func_80095EA0

#include <libaudio.h>
#include "synthInternals.h"
#include <os.h>



#define EQPOWER_LENGTH 128
extern s16 D_800C7AA0[EQPOWER_LENGTH]; /* eqpower */
#define eqpower D_800C7AA0

extern	f64	__pow(f64, f64);

static  Acmd *_pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount,
                            s32 sampleOffset, Acmd *p) ;
static  s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel);

static  f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel);

Acmd *alEnvmixerPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                     Acmd *p) 
{
    Acmd        *ptr = p;
    ALEnvMixer	*e = (ALEnvMixer *)filter;
    s16         inp;
    s32         lastOffset;
    s32         thisOffset = sampleOffset;
    s32         samples;
    s16         loutp = 0;
    s32         fVol;
    ALParam     *thisParam;

    inp = AL_RESAMPLER_OUT;

    while (e->ctrlList != 0) { 
        lastOffset = thisOffset;
        thisOffset = e->ctrlList->delta;
        samples    = thisOffset - lastOffset;
        if (samples > outCount)
            break;

        switch (e->ctrlList->type) {
          case (AL_FILTER_START_VOICE_ALT):
              {                  
                  ALStartParamAlt *param = (ALStartParamAlt *)e->ctrlList;
                  ALFilter     *f = (ALFilter *) e;
                  s32 tmp;

                  if (param->unity) {
                      (*e->filter.setParam)(&e->filter,
                                            AL_FILTER_SET_UNITY_PITCH, 0);
                  }

                  (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                        param->wave);
                  (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);

                  e->first  = 1;

                  e->delta  = 0;
                  e->segEnd = param->samples;

                  tmp = ((s32)param->volume * (s32)param->volume) >> 15;
                  e->volume = (s16) tmp;
                  e->pan    = param->pan;
                  e->dryamt = eqpower[param->fxMix];
                  e->wetamt = eqpower[EQPOWER_LENGTH - param->fxMix - 1];

                  if (param->samples) {
                      e->cvolL  = 1;
                      e->cvolR  = 1;
                  } else {

                      e->cvolL = (e->volume * eqpower[e->pan]) >> 15;
                      e->cvolR = (e->volume *
                                  eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                  }

                  if (f->source) {
                      union {
                          f32 f;
                          s32 i;
                      } data;                    
                      data.f = param->pitch;
                      (*f->source->setParam)(f->source, AL_FILTER_SET_PITCH,
                                            (void *)data.i);
                  }

              }

              break;

          case (AL_FILTER_SET_FXAMT):
          case (AL_FILTER_SET_PAN):
          case (AL_FILTER_SET_VOLUME):
	      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);

              if (e->delta >= e->segEnd){

                  e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
                  e->rtgt = (e->volume *
                             eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
                  e->delta = e->segEnd;   
                  e->cvolL = e->ltgt;
                  e->cvolR = e->rtgt;
              } else {

                  e->cvolL = _getVol(e->cvolL, e->delta, e->lratm, e->lratl);
                  e->cvolR = _getVol(e->cvolR, e->delta, e->rratm, e->rratl);
              }

              if( e->cvolL == 0 ) e->cvolL = 1;
              if( e->cvolR == 0 ) e->cvolR = 1;

              if (e->ctrlList->type == AL_FILTER_SET_PAN)

                  e->pan = (s16) e->ctrlList->data.i;

              if (e->ctrlList->type == AL_FILTER_SET_VOLUME){

                  e->delta = 0;

                  fVol = (e->ctrlList->data.i);
                  fVol = (fVol*fVol)>>15;
                  e->volume = (s16) fVol;

                  e->segEnd = e->ctrlList->moredata.i;

              }

              if (e->ctrlList->type == AL_FILTER_SET_FXAMT){
                  e->dryamt = eqpower[e->ctrlList->data.i];
                  e->wetamt = eqpower[EQPOWER_LENGTH - e->ctrlList->data.i - 1];
              }

              e->first = 1;
              break;

          case (AL_FILTER_START_VOICE):
              {
                  ALStartParam *p = (ALStartParam *)e->ctrlList;

                  if (p->unity) {
                      (*e->filter.setParam)(&e->filter,
                                            AL_FILTER_SET_UNITY_PITCH, 0);
                  }

                  (*e->filter.setParam)(&e->filter, AL_FILTER_SET_WAVETABLE,
                                        p->wave);
                  (*e->filter.setParam)(&e->filter, AL_FILTER_START, 0);
              }
              break;

          case (AL_FILTER_STOP_VOICE):
              {

		  ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
		  (*e->filter.setParam)(&e->filter, AL_FILTER_RESET, 0);
              }
              break;

          case (AL_FILTER_FREE_VOICE):
              {                  
                  ALSynth *drvr = &alGlobals->drvr;
                  ALFreeParam *param = (ALFreeParam *)e->ctrlList;
                  param->pvoice->offset = 0;
                  _freePVoice(drvr, (PVoice *)param->pvoice);
              }
              break;

          default:

	      ptr = _pullSubFrame(e, &inp, &loutp, samples, sampleOffset, ptr);
              (*e->filter.setParam)(&e->filter, e->ctrlList->type,
                                    (void *) e->ctrlList->data.i);
              break;
        }
        loutp  += (samples<<1);
        outCount -= samples;

        thisParam = e->ctrlList;
        e->ctrlList = e->ctrlList->next;
        if (e->ctrlList == 0)
            e->ctrlTail = 0;

        __freeParam(thisParam);

    }

    ptr = _pullSubFrame(e, &inp, &loutp, outCount, sampleOffset, ptr);

    if (e->delta > e->segEnd)
        e->delta = e->segEnd;

    return ptr;
}

s32 alEnvmixerParam(void *filter, s32 paramID, void *param)
{
    ALFilter      *f = (ALFilter *) filter;
    ALEnvMixer	*e = (ALEnvMixer *) filter;

    switch (paramID) {

      case (AL_FILTER_ADD_UPDATE):
          if (e->ctrlTail) {
              e->ctrlTail->next = (ALParam *)param;
          } else {
              e->ctrlList = (ALParam *)param;
          }            
          e->ctrlTail = (ALParam *)param;

          break;

      case (AL_FILTER_RESET):
          e->first = 1;
          e->motion = AL_STOPPED;
          e->volume = 1;
          if (f->source)
              (*f->source->setParam)(f->source, AL_FILTER_RESET, param);
          break;

      case (AL_FILTER_START):
          e->motion = AL_PLAYING;
          if (f->source)
              (*f->source->setParam)(f->source, AL_FILTER_START, param);
          break;

      case (AL_FILTER_SET_SOURCE):
          f->source = (ALFilter *) param;
          break;

      default:
          if (f->source)
              (*f->source->setParam)(f->source, paramID, param);
    }
    return 0;
}
static Acmd* _pullSubFrame(void *filter, s16 *inp, s16 *outp, s32 outCount,
                    s32 sampleOffset, Acmd *p) 
{
    Acmd        *ptr = p;
    ALEnvMixer	*e = (ALEnvMixer *)filter;
    ALFilter      *source= e->filter.source;

    if (e->motion != AL_PLAYING || !outCount)
        return ptr;

    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, A_MAIN, *inp, AL_MAIN_L_OUT + *outp, outCount<<1);
    aSetBuffer(ptr++, A_AUX, AL_MAIN_R_OUT + *outp, AL_AUX_L_OUT + *outp,
	       AL_AUX_R_OUT + *outp);

    if (e->first){
	e->first = 0;

        e->ltgt = (e->volume * eqpower[e->pan]) >> 15;
        e->lratm = _getRate((f64)e->cvolL, (f64)e->ltgt,
                            e->segEnd, &(e->lratl));
        e->rtgt = (e->volume *
                   eqpower[EQPOWER_LENGTH - e->pan - 1]) >> 15;
        e->rratm = _getRate((f64)e->cvolR, (f64)e->rtgt, e->segEnd,
                            &(e->rratl));

        aSetVolume(ptr++, A_LEFT | A_VOL, e->cvolL, 0, 0);
        aSetVolume(ptr++, A_RIGHT | A_VOL, e->cvolR, 0, 0);
	aSetVolume(ptr++, A_LEFT  | A_RATE, e->ltgt, e->lratm, e->lratl);
	aSetVolume(ptr++, A_RIGHT | A_RATE, e->rtgt, e->rratm, e->rratl);
	aSetVolume(ptr++, A_AUX, e->dryamt, 0, e->wetamt);
	aEnvMixer (ptr++, A_INIT | A_AUX, osVirtualToPhysical(e->state));
    }
    else
	aEnvMixer(ptr++, A_CONTINUE | A_AUX, osVirtualToPhysical(e->state));

    *inp += (outCount<<1);
    e->delta += outCount;

    return ptr;
}

#define EXP_MASK  0x7f800000
#define MANT_MASK 0x807fffff

f64
_frexpf(f64 value, s32 *eptr)
{
    f64 absvalue;

    *eptr = 0;
    if (value == 0.0) 
        return (value);
    absvalue = (value > 0.0) ? value : -value;
    for ( ; absvalue >= 1.0; absvalue *= 0.5)
        ++*eptr;
    for ( ; absvalue < 0.5; absvalue += absvalue)
        --*eptr;
    return (value > 0.0 ? absvalue : -absvalue);
}

f64
_ldexpf(f64 in, s32 ex)
{
    s32 exp;

    if ( ex ) {
	exp = 1 << ex;
	in *= (f64)exp;
    }

    return ( in );
}

static
s16 _getRate(f64 vol, f64 tgt, s32 count, u16* ratel)
{
    s16         s;

    f64         invn = 1.0/count, eps, a, fs, mant;
    s32         i_invn, ex, indx;

    if (count == 0){
        if (tgt >= vol){
            *ratel = 0xffff;
            return 0x7fff;
        }
        else{
            *ratel = 0;
            return 0;
        }
    }

    if (tgt < 1.0)
        tgt = 1.0;
    if (vol <= 0) vol = 1;	

#define NBITS (3)
#define NPOS  (1<<NBITS)
#define NFRACBITS (30)
#define M_LN2		0.69314718055994530942

    {
	f64 logtab[] = { -0.912537, -0.752072, -0.607683, -0.476438,
                         -0.356144, -0.245112, -0.142019, -0.045804  };

	i_invn = (s32) _ldexpf( invn, NFRACBITS );
	mant = _frexpf( tgt/vol, &ex );
	indx = (s32) (_ldexpf( mant, NBITS+1 ) ); 
	eps = (logtab[indx - NPOS] + ex) * M_LN2;
	eps /= _ldexpf( 1, NFRACBITS ); 
	fs = (1.0 + eps);
	a = 1.0;
	while( i_invn ) {
	    if( i_invn & 1 )
		a = a * fs;
	    fs *= fs;
	    i_invn >>= 1;
	}
    }

    a *= (a *= (a *= a));
    s = (s16) a;
    *ratel = (s16)(0xffff * (a - (f32) s));

    return (s16)a;

}

static
f32 _getVol(f32 ivol, s32 samples, s16 ratem, u16 ratel)
{
    f32	        r, a;
    s32	      	i;

    samples >>=3;
    if (samples == 0){
        return ivol;
    }
    r = ((f32) (ratem<<16) + (f32) ratel)/65536;

    a = 1.0;
    for (i=0; i<32; i++){
	if( samples & 1 )
	    a *= r;
        samples >>= 1;
        if (samples == 0)
            break;
	r *= r;
    }
    ivol *= a;
    return ivol;
}




#define RANGE 2.0
extern ALGlobals *alGlobals;

#define SWAP(in, out)	\
{			\
     s16 t = out;	\
     out = in;		\
     in = t;		\
}

Acmd *_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, s32 incount, Acmd *p);
Acmd *_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p);
Acmd *_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p);
f32  _doModFunc(ALDelay *d, s32 count);


Acmd *alFxPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                     Acmd *p) 
{
    Acmd        *ptr = p;
    ALFx	*r = (ALFx *)filter;
    ALFilter    *source = r->filter.source;
    s16		i, buff1, buff2, input, output;
    s16		*in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay	*d, *pd;

    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input  = AL_AUX_L_OUT;
    output = AL_AUX_R_OUT;
    buff1  = AL_TEMP_0;
    buff2  = AL_TEMP_1;

    aSetBuffer(ptr++, 0, 0, 0, outCount<<1);  
    aMix(ptr++, 0, 0xda83, AL_AUX_L_OUT, input); 
    aMix(ptr++, 0, 0x5a82, AL_AUX_R_OUT, input); 

    ptr = _saveBuffer(r, r->input, input, outCount, ptr);

    aClearBuffer(ptr++, output, outCount<<1); 

    for (i = 0; i < r->section_count; i++) {
	d  = &r->delay[i];  
	in_ptr  = &r->input[-d->input];
	out_ptr = &r->input[-d->output];

	if (in_ptr == prev_out_ptr) {
	    SWAP(buff1, buff2);
	} else {  
	    ptr = _loadBuffer(r, in_ptr, buff1, outCount, ptr);
	}
	ptr = _loadOutputBuffer(r, d, buff2, outCount, ptr);

	if (d->ffcoef) {
	    aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
	    if (!d->rs && !d->lp) {
		ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);
	    }
	}

	if (d->fbcoef) {
	    aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
	    ptr = _saveBuffer(r, in_ptr, buff1, outCount, ptr);
	}

	if (d->lp)
	    ptr = _filterBuffer(d->lp, buff2, outCount, ptr);

	if (!d->rs)
	    ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);

	if (d->gain)
	    aMix(ptr++, 0, (u16)d->gain, buff2, output);

	prev_out_ptr = &r->input[d->output];
    }

    r->input += outCount;
    if (r->input > &r->base[r->length])
	r->input -= r->length;

    aDMEMMove(ptr++, output, AL_AUX_L_OUT, outCount<<1);

    return ptr;
}

s32 alFxParam(void *filter, s32 paramID, void *param)
{
    if(paramID == AL_FILTER_SET_SOURCE)
    {
	ALFilter    *f = (ALFilter *) filter;
	f->source = (ALFilter*) param;
    }
    return 0;
}

s32 alFxParamHdl(void *filter, s32 paramID, void *param)
{
    ALFx   *f = (ALFx *) filter;    
    s32    p = (paramID - 2) % 8; 
    s32    s = (paramID - 2) / 8;
    s32    val = *(s32*)param;

#define INPUT_PARAM         0
#define OUTPUT_PARAM        1
#define FBCOEF_PARAM        2
#define FFCOEF_PARAM        3
#define GAIN_PARAM          4
#define CHORUSRATE_PARAM    5
#define CHORUSDEPTH_PARAM   6
#define LPFILT_PARAM        7

    switch(p)
    {
        case INPUT_PARAM:
            f->delay[s].input = (u32)val & 0xFFFFFFF8;
            break;
        case OUTPUT_PARAM:
            f->delay[s].output = (u32)val & 0xFFFFFFF8;
            break;
        case FFCOEF_PARAM:
            f->delay[s].ffcoef = (s16)val;
            break;
        case FBCOEF_PARAM:
            f->delay[s].fbcoef = (s16)val;
            break;
        case GAIN_PARAM:
            f->delay[s].gain = (s16)val;
            break;
        case CHORUSRATE_PARAM:

            f->delay[s].rsinc = ((((f32)val)/1000) * RANGE)/alGlobals->drvr.outputRate; 
            break;

#define CONVERT 173123.404906676
#define LENGTH  (f->delay[s].output - f->delay[s].input)

        case CHORUSDEPTH_PARAM:

            f->delay[s].rsgain = (((f32)val) / CONVERT) * LENGTH;
            break;
        case LPFILT_PARAM:
            if(f->delay[s].lp)
            {
                f->delay[s].lp->fc = (s16)val;
                _init_lpfilter(f->delay[s].lp);
            }
            break;
    }
    return 0;
}

Acmd *_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, s32 incount, Acmd *p)
{
    Acmd        *ptr = p;
    s32         ratio, count, rbuff = AL_TEMP_2;
    s16         *out_ptr;
    f32         fincount, fratio, delta;
    s32         ramalign = 0, length;
    static f32  val=0.0, lastval=-10.0;
    static f32  blob=0;

    if (d->rs) {
        length = d->output - d->input;
        delta = _doModFunc(d, incount); 

        delta /= length;  
        delta = (s32)(delta * UNITY_PITCH); 
        delta = delta / UNITY_PITCH;
        fratio = 1.0 - delta;  

        fincount = d->rs->delta + (fratio * (f32)incount);
        count = (s32) fincount; 
        d->rs->delta = fincount - (f32)count; 

        out_ptr = &r->input[-(d->output - d->rsdelta)];
        ramalign = ((s32)out_ptr & 0x7) >> 1; 

        ptr = _loadBuffer(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

        ratio = (s32)(fratio * UNITY_PITCH);

        aSetBuffer(ptr++, 0, rbuff + (ramalign<<1), buff, incount<<1);
        aResample(ptr++, d->rs->first, ratio, osVirtualToPhysical(d->rs->state));

        d->rs->first = 0; 
        d->rsdelta += count - incount; 
    } else {
        out_ptr = &r->input[-d->output];
        ptr = _loadBuffer(r, out_ptr, buff, incount, ptr);
    }

    return ptr;
}

Acmd *_loadBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];

#ifdef _DEBUG
    if(curr_ptr > delay_end)
        __osError(ERR_ALMODDELAYOVERFLOW, 1, delay_end - curr_ptr);
#endif

    if (curr_ptr < r->base)
    curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, buff, 0, before_end<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(curr_ptr));
        aSetBuffer(ptr++, 0, buff+(before_end<<1), 0, after_end<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(r->base));
    } else {
        aSetBuffer(ptr++, 0, buff, 0, count<<1);
        aLoadBuffer(ptr++, osVirtualToPhysical(curr_ptr));
    }

    aSetBuffer(ptr++, 0, 0, 0, count<<1);

    return ptr;

}

Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd    *ptr = p;
    s32     after_end, before_end;
    s16     *updated_ptr, *delay_end;

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base)      
        curr_ptr += r->length;   
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) { 
        after_end = updated_ptr - delay_end;
        before_end = delay_end - curr_ptr;

        aSetBuffer(ptr++, 0, 0, buff, before_end<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
        aSetBuffer(ptr++, 0, 0, buff+(before_end<<1), after_end<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(r->base));
        aSetBuffer(ptr++, 0, 0, 0, count<<1);
    } else {
        aSetBuffer(ptr++, 0, 0, buff, count<<1);
        aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
    }

    return ptr;

}

Acmd *_filterBuffer(ALLowPass *lp, s32 buff, s32 count, Acmd *p)
{
    Acmd	*ptr = p;

    aSetBuffer(ptr++, 0, buff, buff, count<<1);
    aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
    aPoleFilter(ptr++, lp->first, lp->fgain, osVirtualToPhysical(lp->fstate));
    lp->first = 0;

    return ptr;
}

f32 _doModFunc(ALDelay *d, s32 count)
{
  f32 val;

  d->rsval += d->rsinc * count;
  d->rsval = (d->rsval > RANGE) ? d->rsval-(RANGE*2) : d->rsval;

  val = d->rsval;
  val = (val < 0) ? -val : val;

  val -= RANGE/2;

  return(d->rsgain * val);
}

