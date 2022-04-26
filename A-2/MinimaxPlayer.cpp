/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#include "MinimaxUtil.h"
#include <climits>

using std::vector;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
	
	std::vector<std::pair<int, int>> nextMoves = sucessors(*b, b->get_p2_symbol());
	int min = INT_MAX;
	std::pair<int, int> minMove(-1, -1);

	for(int i = 0; i < nextMoves.size(); i++) {

		OthelloBoard tB = (*b);
		tB.play_move((nextMoves.at(i)).first, (nextMoves.at(i)).second, b->get_p1_symbol());
		int nextMax = maxValue(tB);
		if(nextMax < min) {
			minMove = nextMoves.at(i);
			min = nextMax;
		}

	}

	col = minMove.first;
	row = minMove.second;

}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}