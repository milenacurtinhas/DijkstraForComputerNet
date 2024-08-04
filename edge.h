#ifndef _EDGE_H_
#define _EDGE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tail;
    double dist;
}Edge;

Edge *edge_construct(int id, double value);
void edgeDestroy(Edge *edge);

#endif