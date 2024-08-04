#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"


Item make_item(int id, double value, Item *parent) {
    Item t;
    id(t) = id;
    value(t) = value;
    parent(t) = parent;
    return t;
}
static void swap(int i, int j, int *map, Item *pq) {
    exch(pq[i], pq[j]);
    map[id(pq[i])] = i;
    map[id(pq[j])] = j;
}

void fix_up(Item *a, int k, int *map) {
    while (k > 1 && more(a[k/2], a[k])) {
        swap(k, k/2, map, a);
        k = k/2;
    }
}

void fix_down(Item *a, int sz, int k, int *map){
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && more(a[j], a[j+1])){
      j++;
    }
    if (!more(a[k], a[j])) {
      break;
    }
    swap(k, j, map, a);
    k = j;
  }
}

Item *PQ_init(int maxN, int *map) {
    Item *pq = (Item *) malloc((maxN+1) * sizeof (Item));
   
    
    return pq;
}

void PQ_insert(Item *pq ,Item v, int *map, int N) {
    pq[N] = v;
    map[id(v)] = N;
    fix_up(pq, N, map);
}

Item PQ_delmin(Item *pq, int N, int *map) {
    Item min = pq[1];
    swap(1, N, map, pq);
    N--;
    fix_down(pq, N, 1, map);
    return min;
}

Item PQ_min(Item *pq) {
    return pq[1];
}

void PQ_decrease_key(int id, double value, int *map, Item *pq) {
    int i = map[id];
    value(pq[i]) = value;
    fix_up(pq, i, map);
}

Item PQ_find(Item *pq, int id, int *map) {
    return pq[map[id]];
}

void PQ_finish(int *visited, int *map, Item *pq) {
    free(visited);
    free(map);
    free(pq);
}