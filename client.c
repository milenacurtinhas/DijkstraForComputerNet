#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "item.h"
#include "vertex.h"
#include "dijkstra.h"
#include "RTT.h"

int main(int argc, char *argv[]) {
    
    FILE* file = fopen(argv[1], "r");

    int i, v, e, sSize, cSize, mSize, x, y;
    int *s, *c, *m;
    double z;

    fscanf(file, "%d", &v);
    fscanf(file, "%d", &e);
    fscanf(file, "%d", &sSize);
    fscanf(file, "%d", &cSize);
    fscanf(file, "%d", &mSize);

    s = (int*) malloc(sSize * sizeof(int));
    c = (int*) malloc(cSize * sizeof(int));
    m = (int*) malloc(mSize * sizeof(int));

    for(i = 0; i < sSize; i++){
        fscanf(file, "%d", &s[i]);
    }

    for(i = 0; i < cSize; i++){
        fscanf(file, "%d", &c[i]);
    }
    
    for(i = 0; i < mSize; i++){
        fscanf(file, "%d", &m[i]);
    }

    Vertex **vertexes = malloc(v * sizeof(Vertex*));
    
    for (i = 0; i < v; i++){
        vertexes[i] = vertexInitialize(i);
    }
    
    for(i = 0; i < e; i++){
        fscanf(file, "%d %d %lf", &x, &y, &z);
        vertexAddEdge(vertexes[x], y, z);
    }

    Item ***resultS = malloc(sizeof(Item**)*sSize);
    Item ***resultC = malloc(sizeof(Item**)*cSize);
    Item ***resultM = malloc(sizeof(Item**)*mSize);
    
    for(i = 0; i < sSize; i++){
        resultS[i] = dijkstra(vertexes, v, s[i]);
    }

    for(i = 0; i < cSize; i++){
        resultC[i] = dijkstra(vertexes, v, c[i]);
    }

    for(i = 0; i < mSize; i++){
        resultM[i] = dijkstra(vertexes, v, m[i]);
    }

    RTT *rtt = malloc(sizeof(RTT)*sSize*cSize);
    RTT *rttStar = malloc(sizeof(RTT)*sSize*cSize);
    
    realRTT(s, sSize, c, cSize, resultS, resultC, rtt);
    RTTStar(s, sSize, c, cSize, m, mSize, resultS, resultC, resultM, rttStar);
    percentage(rtt, rttStar, sSize*cSize);

    FILE* output = fopen(argv[2], "w");

    for(i = 0; i < sSize*cSize; i++){
        fprintf(output, "%d %d %.16lf\n", rtt[i].v1, rtt[i].v2, rtt[i].value);
    }
    
    vertexesDestroy(vertexes, v);
    for(i = 0; i < sSize; i++){
        dijkstraDestroy(resultS[i], v);
    }
    for(i = 0; i < cSize; i++){
        dijkstraDestroy(resultC[i], v);
    }
    for(i = 0; i < mSize; i++){
        dijkstraDestroy(resultM[i], v);
    }
    free(s);
    free(c);
    free(m);
    free(rtt);
    free(rttStar);
    free(resultS);
    free(resultC);
    free(resultM);
    fclose(file);
    fclose(output);
}