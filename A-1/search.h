#ifndef SEARCH_H
#define SEARCH_H

struct graphNode {

    void* val;
    struct graphNode* parent;
    struct graphNode** children;

};

#endif