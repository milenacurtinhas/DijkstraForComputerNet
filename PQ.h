#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

Item make_item(int id, double value, Item *parent);
static void swap(int i, int j, int *map, Item *pq);
void fix_up(Item *a, int k, int *map) ;
void fix_down(Item *a, int sz, int k, int *map);
Item *PQ_init(int maxN, int *map);                              // cria uma min PQ com capacidade maxN
void PQ_insert(Item *pq ,Item v, int *map, int N);              // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Item PQ_delmin(Item *pq, int N, int *map);                      // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(int id, double value, int *map, Item *pq); // Muda a prioridade do nó com identificador 'id' para 'value'
Item PQ_min(Item *pq);                                          // Retorna Item com menor campo 'value' da PQ
Item PQ_find(Item *pq, int id, int *map);
void PQ_finish(int *visited, int *map, Item *pq);                // Libera memória

#endif
