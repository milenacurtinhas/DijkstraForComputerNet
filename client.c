#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "item.h"

Item make_item(int id, double value) {
    Item t;
    id(t) = id;
    value(t) = value;
    return t;
}

int main(int argc, char *argv[]) {
    
    FILE* file = fopen(argv[1], "r");

    int i, v, e, sSize, cSize, mSize, x, y;
    int *s, *c, *m;
    float z;

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

    for(i = 0; i < e; i++){
        fscanf(file, "%d %d %f", &x, &y, &z);
    }

    fclose(file);
    
    // inicializando a PQ
    // PQ_init(10);

    // // inserindo alguns elementos na PQ
    // PQ_insert(make_item(1, 10.0));
    // PQ_insert(make_item(6, 5.0));
    // PQ_insert(make_item(3, 3.0));
    // PQ_insert(make_item(4, 4.0));
    // PQ_insert(make_item(7, 7.0));
    // PQ_insert(make_item(2, 1.0));

    // // alterando a prioridade de alguns elementos
    // PQ_decrease_key(4, 0.5); // agora o nó 4 tem valor 0.5, sua posição no heap deve mudar
    // PQ_decrease_key(6, 0.1); // agora o nó 6 tem valor 0.1, sua posição no heap deve mudar

    // // removendo o menor elemento e imprimindo
    // while (!PQ_empty()) {
    //     Item p = PQ_delmin();
    //     printf("Identificador %d, prioridade %lf\n", id(p), value(p));
    // }
}
