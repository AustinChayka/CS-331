#include "OthelloBoard.h"
#include <stdio.h>
#include <iostream>
#include "MinimaxUtil.h"
#include <cstdlib>

int main(int argc, char** argv) {

    OthelloBoard* b = new OthelloBoard(4, 4, 'X', 'O');
	b->initialize();
    b->display();

    std::vector<std::pair<int, int>> next = sucessors(*b, b->get_p1_symbol());
    std::pair<int, int> move = next.at(rand() % next.size());
    b->play_move(move.first, move.second, b->get_p1_symbol());
    b->display();

    next = sucessors(*b, b->get_p2_symbol());
    std::cout << "Next possible moves: " << std::endl;
    for(int i = 0; i < next.size(); i++) {
        OthelloBoard tB = (*b);
        tB.play_move(next.at(i).first, next.at(i).second, b->get_p2_symbol());
        printf("Max Utility: %d\n", maxValue(tB));
        tB.display();
    }

    return 0;

}