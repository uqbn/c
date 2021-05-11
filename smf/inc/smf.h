/*************************************************
 * 
 * 
*/
#ifndef __SMF_H__
#define __SMF_H__
/*************************************************/

/*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "smf_pd.h"
/*************************************************/
#define HELP "\
Usage : smf cmd [arg]\n\
    cmd init,add,del,edit,create,out,in\n\
    -f,--file=<filename>\n\
    -n,--name=<name>\n\
    -p,--password=<passowrd>\n\
    -t,--type=<int>\n\
    -l,--length=<int>\n\
    -o,--out=<outfile>\n\
    -i,--in=<infile>"
/*************************************************/

typedef enum
{
    USE_INIT,
    USE_ADD,
    USE_DEL,
    USE_EDIT,
    USE_CREATE,
    USE_OUT,
    USE_IN,
    USE_FIND
} Use;

typedef struct Pd_data
{
    char *dataname;
    char *inname;
    char *outname;
} Pd_data;

/*************************************************/
void runpd(const char *const bin, Use use, const Password *const pd, const Pd_data *const pd_data);
/*************************************************/
#endif /* __SMF_H__ */