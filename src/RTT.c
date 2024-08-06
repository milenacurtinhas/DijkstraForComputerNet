#include "RTT.h"

RTT rtt_construct(int v1, int v2, double value){
    RTT r;
    r.v1 = v1;
    r.v2 = v2;
    r.value = value;

    return r;
}

void realRTT(int *s, int sSize, int *c, int cSize, Item ***resultS, Item ***resultC, RTT *rtt){
    int i, j, x, y, k = 0;

    for(i = 0; i < sSize; i++){
        x = s[i];

        for(j = 0; j < cSize; j++){            
            y = c[j];
            double sum = resultS[i][y]->value + resultC[j][x]->value;
            rtt[k] = rtt_construct(x, y, sum);  
            k++;
        }
    }
}

void RTTStar(int *s, int sSize, int *c, int cSize, int *m, int mSize, Item ***resultS, Item ***resultC, Item ***resultM, RTT *rttStar){
    int i, j, x, y, n = 0;

    for(i = 0; i < sSize; i++){
        x = s[i];
       
        for(j = 0; j < cSize; j++){
            y = c[j];
            double minRtt = INFINITY;

            for(int k = 0; k < mSize; k++){
                int z = m[k];
                double r = resultS[i][z]->value + resultM[k][x]->value + resultM[k][y]->value + resultC[j][z]->value;
                
                if(r < minRtt){
                    minRtt = r;
                }               
            }
            rttStar[n] = rtt_construct(x, y, minRtt);
            n++;
        }
    }
}

void percentage(RTT *rtt, RTT *rttStar, int size){
    int i;

    for(i = 0; i < size; i++){
        rtt[i].value = rttStar[i].value/rtt[i].value;
    }
    qsort(rtt, size, sizeof(RTT), compareRTT);
}

int compareRTT(const void *a, const void *b) {
    RTT *rttA = (RTT *)a;
    RTT *rttB = (RTT *)b;

    if (rttA->value < rttB->value) return -1;
    if (rttA->value > rttB->value) return 1;

    return 0;
}