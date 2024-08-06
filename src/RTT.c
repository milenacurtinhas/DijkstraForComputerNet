#include "RTT.h"

RTT rtt_construct(int v1, int v2, double value){
    RTT r;
    r.v1 = v1;
    r.v2 = v2;
    r.value = value;

    return r;
}