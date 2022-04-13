#ifndef UTIL_H
#define UTIL_H

#define RESIZE 4
#define TRUE 1
#define BOOL int
#define FALSE 0
#define NULL 0

struct list {

    void** vals;
    int size;
    int cap;

};

struct list* init(int);
void* get(struct list*, int);
void pushBack(struct list*, void*);
void pushFront(struct list*, void*);
void* pullBack(struct list*);
void* pullFront(struct list*);
void resize(struct list*, int);
void clean(struct list*);

#endif