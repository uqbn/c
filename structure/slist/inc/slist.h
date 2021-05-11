#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Slistc
{
    char ch;
    struct Slistc *next;
} Slistc;

Slistc *slistc_init(void);
void slistc_free(Slistc *_ph);

Slistc *slistc_ato(const char *_src);
Slistc *slistc_aton(const char *_src, size_t _max);

char *slistc_toa(const Slistc *_ph);
char *slistc_toan(const Slistc *_ph, size_t _max);

ssize_t slistc_add(Slistc *_ph, char _ch);
ssize_t slistc_ins(Slistc *_ph, size_t _index, char _ch);
ssize_t slistc_mod(Slistc *_ph, size_t _index, char _ch);

Slistc *slistc_cut(Slistc *_ph, size_t _index1, size_t _index2);
ssize_t slistc_del(Slistc *_ph, size_t _index1, size_t _index2);
Slistc *slistc_sli(Slistc *_ph, size_t _index1, size_t _index2);

ssize_t slistc_chr(const Slistc *_ph, char _ch);
ssize_t slistc_rchr(const Slistc *_ph, char _ch);

ssize_t slistc_swap(Slistc *_ph, size_t _index1, size_t _index2);
ssize_t slistc_swaps(Slistc *_ph, ssize_t _index1, ssize_t _max1, ssize_t _index2, ssize_t _max2);

ssize_t slistc_len(const Slistc *_ph);
ssize_t slistc_nlen(const Slistc *_ph, size_t _max);

ssize_t slistc_put(const Slistc *_ph, FILE *_fp);
ssize_t slistc_putn(const Slistc *_ph, size_t _count, FILE *_fp);

ssize_t slistc_cpy(Slistc *_dst, const Slistc *_src);
ssize_t slistc_cpyn(Slistc *_dst, const Slistc *_src, size_t _max);

ssize_t slistc_cpyi(Slistc *_dst, size_t _index, const Slistc *_src);
ssize_t slistc_cpyin(Slistc *_dst, size_t _index, const Slistc *_src, size_t _max);

ssize_t slistc_cat(Slistc *_dst, const Slistc *_src);
ssize_t slistc_catn(Slistc *_dst, const Slistc *_src, size_t _max);

ssize_t slistc_cmp(const Slistc *_dst, const Slistc *_src);
ssize_t slistc_cmpn(const Slistc *_dst, const Slistc *_src, size_t _max);

ssize_t slistc_str(const Slistc *_dst, const Slistc *_src);
ssize_t slistc_rstr(const Slistc *_dst, const Slistc *_src);

ssize_t slistc_inss(Slistc *_dst, size_t _index, const Slistc *_src);
ssize_t slistc_inssn(Slistc *_dst, size_t _index, const Slistc *_src, size_t _max);

ssize_t slistc_cou(const Slistc *_dst, const Slistc *_src);

ssize_t slistc_dels(Slistc *_dst, const Slistc *_src);
ssize_t slistc_delsi(Slistc *_dst, const Slistc *_src, size_t _index);
ssize_t slistc_dels1(Slistc *_dst, const Slistc *_src);
ssize_t slistc_rdels1(Slistc *_dst, const Slistc *_src);
ssize_t slistc_delsn(Slistc *_dst, const Slistc *_src, size_t _n);
ssize_t slistc_rdelsn(Slistc *_dst, const Slistc *_src, size_t _n);

ssize_t slistc_mods(Slistc *_dst, const Slistc *_old, const Slistc *_new);
ssize_t slistc_modsi(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _index);
ssize_t slistc_mods1(Slistc *_dst, const Slistc *_old, const Slistc *_new);
ssize_t slistc_rmods1(Slistc *_dst, const Slistc *_old, const Slistc *_new);
ssize_t slistc_modsn(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _n);
ssize_t slistc_rmodsn(Slistc *_dst, const Slistc *_old, const Slistc *_new, size_t _n);

#endif