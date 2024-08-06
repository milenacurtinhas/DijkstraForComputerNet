#include "edge.h"

Edge *edge_construct(int id, double value){
    Edge *e = malloc(sizeof(Edge));
    e->tail = id;
    e->dist = value;

    return e;
}

void edgeDestroy(Edge *edge){
    free(edge);
}