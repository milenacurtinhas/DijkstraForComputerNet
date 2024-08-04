#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <stdio.h>
#include <stdlib.h>
#include "edge.h"
#include "PQ.h"
#include "vertex.h"

Item *dijkstra(Vertex **vertexes, int vertexesQtt, int startID);
void relax(int k, Item *pq, int *map, double dist, Item adjacent, Item item);

#endif