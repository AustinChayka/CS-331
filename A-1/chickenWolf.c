#include "chickenWolf.h"

#include <stdio.h>

struct state* newState(int leftChickens, int leftWolves, int leftBoat, int rightChickens, int rightWolves, int rightBoat) {

    if(leftChickens < 0 || leftWolves < 0 || leftBoat < 0 || rightChickens < 0 || rightWolves < 0 || rightBoat < 0 || leftBoat > 1 || rightBoat > 1) return NULL;

    struct state* s = malloc(sizeof(struct state));
    s->leftBank[CHICKENS] = leftChickens;
    s->leftBank[WOLVES] = leftWolves;
    s->leftBank[BOAT] = leftBoat;
    s->rightBank[CHICKENS] = rightChickens;
    s->rightBank[WOLVES] = rightWolves;
    s->rightBank[BOAT] = rightBoat;

    return s;

}

struct list* nextStates(struct state* s) {

    struct list* l = init(0);

    for(int act = 0; act < 5; act++) {

        struct state* ns = alterState(s, act);
        if(isValidState(ns)) pushBack(l, ns);
        else free(ns);

    }

    return l;

}

struct state* alterState(struct state* s, enum action act) {

    int leftChickens = s->leftBank[CHICKENS], 
        leftWolves = s->leftBank[WOLVES],
        rightChickens = s->rightBank[CHICKENS],
        rightWolves = s->rightBank[WOLVES],
        leftBoat = s->leftBank[BOAT] ? 1 : -1,
        rightBoat = s->rightBank[BOAT] ? 1 : -1;

    switch(act) {

        case move_1_chicken:
            leftChickens += 1 * rightBoat;
            rightChickens += 1 * leftBoat;
            break;
        case move_2_chickens:
            leftChickens += 2 * rightBoat;
            rightChickens += 2 * leftBoat;
            break;
        case move_1_wolf:        
            leftWolves += 1 * rightBoat;
            rightWolves += 1 * leftBoat;
            break;
        case move_2_wolves:        
            leftWolves += 2 * rightBoat;
            rightWolves += 2 * leftBoat;
            break;
        case move_1_each:
            leftChickens += 1 * rightBoat;
            rightChickens += 1 * leftBoat;        
            leftWolves += 1 * rightBoat;
            rightWolves += 1 * leftBoat;
            break;

    }

    return newState(leftChickens, leftWolves, leftBoat == -1 ? 1 : 0, rightChickens, rightWolves, rightBoat == -1 ? 1 : 0);

}


BOOL isValidState(struct state* s) {

    if(s == NULL) return FALSE;

    if(s->leftBank[CHICKENS] > 0 && s->leftBank[CHICKENS] < s->leftBank[WOLVES]) return FALSE;
    if(s->rightBank[CHICKENS] > 0 && s->rightBank[CHICKENS] < s->rightBank[WOLVES]) return FALSE;

    return TRUE;

}

void printState(struct state* s) {

    printf("[%d %d %d] | [%d %d %d]\n", s->leftBank[CHICKENS], s->leftBank[WOLVES], s->leftBank[BOAT], s->rightBank[CHICKENS], s->rightBank[WOLVES], s->rightBank[BOAT]);

}