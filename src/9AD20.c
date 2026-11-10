/* libultra libc/xlitob.c (_Litob). The digit strings live in the data asm. */
#define _Litob func_8009A120
#define lldiv func_8009AE74
#include "sdk_xstdio.h"
#include "libc/string.h"

#define BUFF_LEN 0x18

extern char D_800C7BE0[]; /* ldigs "0123456789abcdef" */
extern char D_800C7BF4[]; /* udigs "0123456789ABCDEF" */
#define ldigs D_800C7BE0
#define udigs D_800C7BF4

void _Litob(_Pft* px, char code) {
    char buff[BUFF_LEN];
    const char* digs;
    int base;
    int i;
    unsigned long long ullval;

    digs = (code == 'X') ? udigs : ldigs;

    base = (code == 'o') ? 8 : ((code != 'x' && code != 'X') ? 10 : 16);
    i = BUFF_LEN;
    ullval = px->v.ll;

    if ((code == 'd' || code == 'i') && px->v.ll < 0) {
        ullval = -ullval;
    }

    if (ullval != 0 || px->prec != 0) {
        buff[--i] = digs[ullval % base];
    }

    px->v.ll = ullval / base;

    while (px->v.ll > 0 && i > 0) {
        lldiv_t qr = lldiv(px->v.ll, base);

        px->v.ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }

    px->n1 = BUFF_LEN - i;

    memcpy((void*)px->s, buff + i, px->n1);

    if (px->n1 < px->prec) {
        px->nz0 = px->prec - px->n1;
    }

    if (px->prec < 0 && (px->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
        if ((i = px->width - px->n0 - px->nz0 - px->n1) > 0) {
            px->nz0 += i;
        }
    }
}
