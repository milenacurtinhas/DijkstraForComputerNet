#ifndef _RTT_H_
#define _RTT_H_
#include <stdio.h>

typedef struct{
    int v1;
    int v2;
    double value;
}RTT;

RTT rtt_construct(int v1, int v2, double value);

#endif