#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <stdio.h>
#include <stdlib.h>
#include "edge.h"

typedef struct{
    int id;
    int adjacencyQtt;
    Edge **adjacencyList;
}Vertex;

Vertex* vertexInitialize(int id);
void vertexAddEdge(Vertex *v, int y, double z);
void vertexesDestroy(Vertex **vertexes, int quantity);
void vertexDestroy(Vertex *vertex);

#endif