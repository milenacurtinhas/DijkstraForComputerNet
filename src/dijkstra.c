#include <math.h>
#include "dijkstra.h"
#include "PQ.h"
#include "item.h"
#include "vertex.h"

Item **dijkstra(Vertex **vertexes, int vertexesQtt, int startID){
    int i, j, k;
    int *visited = (int*) malloc(vertexesQtt* sizeof(int));   
    int *map = (int *) malloc((vertexesQtt+1) * sizeof (int));

    Item **pq = PQ_init(vertexesQtt, map);
    int pqQtt = 0;
    Item *item;
    Vertex *vertex;
    Edge *edge;
    Item **result = malloc(sizeof(Item*)*vertexesQtt);

    for(i = 0; i < vertexesQtt; i++){
        pqQtt++;
        
        if(i == startID){
            item = make_item(startID, 0, NULL);
            PQ_insert(pq, item, map, pqQtt);
        }
        else{
            item = make_item(i, INFINITY, NULL);
            PQ_insert(pq, item, map, pqQtt);
        }

        result[i] = item;            
        visited[i] = 0;        
    }
    
    while(pqQtt){
        item = PQ_delmin(pq, pqQtt, map);
        pqQtt--;
        i = id(item);
        visited[i] = 1;
        vertex = vertexes[i];

        for(j = 0; j < vertex->adjacencyQtt; j++){
            edge = vertex->adjacencyList[j];
            k = edge->tail;
            Item* adjacent = PQ_find(pq, k, map);
            
            if(!visited[k]){
                relax(k, pq, map, edge->dist, adjacent, item);
            }
        }
    }

     for(i = 0; i < vertexesQtt; i++){
        Item* adjacent = result[i];
        printf("Distancia de %d a %d: %.20lf\n", startID, adjacent->id, adjacent->value);
     }

    PQ_finish(visited, map, pq);

    return(result);
}

void relax(int k, Item **pq, int *map, double dist, Item *adjacent, Item *item){
    if(adjacent->value > item->value + dist){
        double val = item->value + dist;
        PQ_decrease_key(k, val, map, pq); //!!!
    }
}

void dijkstraDestroy(Item **result, int vertexesQtt){
    int i;
    for(i = 0; i < vertexesQtt; i++){
        free(result[i]);
    }
    free(result);
}