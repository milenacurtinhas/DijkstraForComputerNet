#ifndef ITEM_H
#define ITEM_H

typedef struct Item{
  int id;           // identificador do nó
  double value;     // valor associado ao nó
  struct Item *parent;       // ponteiro para o nó predecessor
} Item;

#define id(A)           (A.id)                          // retorna identificador do nó
#define value(A)        (A.value)                       // retorna valor do nó
#define parent(A)       (A.parent)                      
#define more(A, B)      (value(A) > value(B))           // compara nós, por valor
#define exch(A, B)      { Item t = A; A = B; B = t; }   // troca dois nós

Item make_item(int id, double value, Item *parent);

#endif
