#ifndef _RTT_H_
#define _RTT_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

typedef struct{
    int v1;
    int v2;
    double value;
}RTT;

RTT rtt_construct(int v1, int v2, double value);
void realRTT(int *s, int sSize, int *c, int cSize, Item ***resultS, Item ***resultC, RTT *rtt);
void RTTStar(int *s, int sSize, int *c, int cSize, int *m, int mSize, Item ***resultS, Item ***resultC, Item ***resultM, RTT *rttStar);
void percentage(RTT *rtt, RTT *rttStar, int size);
int compareRTT(const void *a, const void *b);

#endif