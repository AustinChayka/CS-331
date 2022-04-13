#include "chickenWolf.h"

int main(int argc, char** argv) {

    struct state* start = newState(3, 3, 1, 0, 0, 0);
    printf("start:\n");
    printState(start);

    struct list* next = nextStates(start);    
    printf("next:\n");
    for(int i = 0; i < next->size; i++) printState(get(next, i));

    return 0;

} 