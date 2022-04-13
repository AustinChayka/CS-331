#ifndef CHICHENWOLF_H
#define CHICKENWOLF_H

#include "util.h"

#define CHICKENS 0
#define WOLVES 1
#define BOAT 2

enum action {
    move_1_chicken = 0,
    move_2_chickens = 1,
    move_1_wolf = 2,
    move_2_wolves = 3,
    move_1_each = 4
};

struct state {

    int leftBank[3];
    int rightBank[3];

};

struct state* newState(int, int, int, int, int, int);
struct list* nextStates(struct state*);
struct state* alterState(struct state*, enum action);
BOOL isValidState(struct state*);
void printState(struct state*);

#endif