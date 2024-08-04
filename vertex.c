#include "vertex.h"

Vertex* vertexInitialize(int id){
    Vertex *v = malloc(sizeof(Vertex));
    v->id = id;
    v->adjacencyQtt = 0;
    v->adjacencyList = NULL;

    return v;
}

void vertexAddEdge(Vertex *v, int y, double z){
    v->adjacencyQtt++;
    v->adjacencyList = realloc(v->adjacencyList, v->adjacencyQtt * sizeof(Edge*));
    v->adjacencyList[v->adjacencyQtt - 1] = edge_construct(y, z);
}

void vertexesDestroy(Vertex **vertexes, int quantity){
    for(int i = 0; i < quantity; i++){
        vertexDestroy(vertexes[i]);
    }
    free(vertexes);
}

void vertexDestroy(Vertex *vertex){
    for(int i = 0; i < vertex->adjacencyQtt; i++){
        edgeDestroy(vertex->adjacencyList[i]);
    }
    free(vertex->adjacencyList);
    free(vertex);
}