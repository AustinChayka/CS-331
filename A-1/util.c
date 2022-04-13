#include "util.h"

#include <stdlib.h>

struct list* init(int n) {

    struct list* l = malloc(sizeof(struct list));
    l->cap = n;
    l->size = 0;
    l->vals = malloc(sizeof(void*) * n);

    return l;

}

void* get(struct list* l, int i) {

    return l->vals[i];

}

void pushBack(struct list* l, void* v) {

    if(l->size >= l->cap) resize(l, l->cap + RESIZE);
    l->vals[l->size] = v;
    l->size++;

}

void pushFront(struct list* l, void* v) {

    if(l->size >= l->cap) resize(l, l->cap + RESIZE);
    for(int i = l->size + 1; i >= 1; i--) {
        l->vals[i] = l->vals[i - 1];
    }
    l->vals[0] = v;
    l->size++;

}

void* pullBack(struct list* l) {

    return l->vals[l->size--];

}

void* pullFront(struct list* l) {

    void* v = l->vals[0];
    for(int i = 0; i < l->size - 1; i++) {
        l->vals[i] = l->vals[i + 1];
    }
    l->size--;
    return v;

}

void resize(struct list* l, int n) {

    realloc(l->vals, n);
    l->cap = n;

}

void clean(struct list* l) {

    free(l->vals);
    free(l);
    l = 0;

}