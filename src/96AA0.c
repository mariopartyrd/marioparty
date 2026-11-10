/* libultra audio/drvrnew.c (2.0I). The effect parameter tables are static data in the data asm. */
#define alFilterNew func_8009A0E0
#define alFxNew func_80095F44
#define _init_lpfilter func_80095EA0
#define alFxPull func_80097380
#define alFxParam func_800976F4
#define alFxParamHdl func_80097708
#define alEnvmixerPull func_800966D0
#define alSavePull func_80097F20

#include <libaudio.h>
#include "synthInternals.h"

#define SCALE 16384

extern s32 D_800C7910[]; /* SMALLROOM_PARAMS */
extern s32 D_800C7978[]; /* BIGROOM_PARAMS */
extern s32 D_800C7A00[]; /* ECHO_PARAMS */
extern s32 D_800C7A28[]; /* CHORUS_PARAMS */
extern s32 D_800C7A50[]; /* FLANGE_PARAMS */
extern s32 D_800C7A78[]; /* NULL_PARAMS */

void _init_lpfilter(ALLowPass* lp) {
    s32 i, temp;
    s16 fc;
    f64 ffc, fcoef;

    temp = lp->fc * SCALE;
    fc = temp >> 15;
    lp->fgain = SCALE - fc;
    lp->first = 1;
    for (i = 0; i < 8; i++) {
        lp->fcvec.fccoef[i] = 0;
    }
    lp->fcvec.fccoef[i++] = fc;
    fcoef = ffc = (f64)fc / SCALE;
    for (; i < 16; i++) {
        fcoef *= ffc;
        lp->fcvec.fccoef[i] = (s16)(fcoef * SCALE);
    }
}

void alFxNew(ALFx* r, ALSynConfig* c, ALHeap* hp) {
    u16 i, j, k;
    s32* param = 0;
    ALFilter* f = (ALFilter*)r;
    ALDelay* d;

    alFilterNew(f, 0, alFxParam, AL_FX);
    f->handler = alFxPull;
    r->paramHdl = (ALSetFXParam)alFxParamHdl;
    switch (c->fxType) {
        case AL_FX_SMALLROOM: param = D_800C7910; break;
        case AL_FX_BIGROOM:   param = D_800C7978; break;
        case AL_FX_ECHO:      param = D_800C7A00; break;
        case AL_FX_CHORUS:    param = D_800C7A28; break;
        case AL_FX_FLANGE:    param = D_800C7A50; break;
        case AL_FX_CUSTOM:    param = c->params;  break;
        default:              param = D_800C7A78; break;
    }
    j = 0;
    r->section_count = param[j++];
    r->length = param[j++];
    r->delay = alHeapAlloc(hp, r->section_count, sizeof(ALDelay));
    r->base = alHeapAlloc(hp, r->length, sizeof(s16));
    r->input = r->base;
    for (k = 0; k < r->length; k++) {
        r->base[k] = 0;
    }
    for (i = 0; i < r->section_count; i++) {
        d = &r->delay[i];
        d->input = param[j++];
        d->output = param[j++];
        d->fbcoef = param[j++];
        d->ffcoef = param[j++];
        d->gain = param[j++];
        if (param[j]) {
#define RANGE 2.0
            d->rsinc = ((((f32)param[j++]) / 1000) * RANGE) / c->outputRate;
#define CONVERT 173123.404906676
#define LENGTH (d->output - d->input)
            d->rsgain = (((f32)param[j++]) / CONVERT) * LENGTH;
            d->rsval = 1.0;
            d->rsdelta = 0.0;
            d->rs = alHeapAlloc(hp, 1, sizeof(ALResampler));
            d->rs->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
            d->rs->delta = 0.0;
            d->rs->first = 1;
        } else {
            d->rs = 0;
            j++;
            j++;
        }
        if (param[j]) {
            d->lp = alHeapAlloc(hp, 1, sizeof(ALLowPass));
            d->lp->fstate = alHeapAlloc(hp, 1, sizeof(POLEF_STATE));
            d->lp->fc = param[j++];
            _init_lpfilter(d->lp);
        } else {
            d->lp = 0;
            j++;
        }
    }
}

void alEnvmixerNew(ALEnvMixer* e, ALHeap* hp) {
    alFilterNew((ALFilter*)e, alEnvmixerPull, alEnvmixerParam, AL_ENVMIX);
    e->state = alHeapAlloc(hp, 1, sizeof(ENVMIX_STATE));
    e->first = 1;
    e->motion = AL_STOPPED;
    e->volume = 1;
    e->ltgt = 1;
    e->rtgt = 1;
    e->cvolL = 1;
    e->cvolR = 1;
    e->dryamt = 0;
    e->wetamt = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->lratm = 1;
    e->lratl = 0;
    e->delta = 0;
    e->segEnd = 0;
    e->pan = 0;
    e->ctrlList = 0;
    e->ctrlTail = 0;
    e->sources = 0;
}

void alLoadNew(ALLoadFilter* f, ALDMANew dmaNew, ALHeap* hp) {
    s32 i;

    alFilterNew((ALFilter*)f, alAdpcmPull, alLoadParam, AL_ADPCM);
    f->state = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->lstate = alHeapAlloc(hp, 1, sizeof(ADPCM_STATE));
    f->dma = dmaNew(&f->dmaState);
    f->lastsam = 0;
    f->first = 1;
    f->memin = 0;
}

void alResampleNew(ALResampler* r, ALHeap* hp) {
    alFilterNew((ALFilter*)r, alResamplePull, alResampleParam, AL_RESAMPLE);
    r->state = alHeapAlloc(hp, 1, sizeof(RESAMPLE_STATE));
    r->delta = 0.0;
    r->first = 1;
    r->motion = AL_STOPPED;
    r->ratio = 1.0;
    r->upitch = 0;
    r->ctrlList = 0;
    r->ctrlTail = 0;
}

void alAuxBusNew(ALAuxBus* m, void* sources, s32 maxSources) {
    alFilterNew((ALFilter*)m, alAuxBusPull, alAuxBusParam, AL_AUXBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter**)sources;
}

void alMainBusNew(ALMainBus* m, void* sources, s32 maxSources) {
    alFilterNew((ALFilter*)m, alMainBusPull, alMainBusParam, AL_MAINBUS);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = (ALFilter**)sources;
}

void alSaveNew(ALSave* f) {
    alFilterNew((ALFilter*)f, alSavePull, alSaveParam, AL_SAVE);
    f->dramout = 0;
    f->first = 1;
}
