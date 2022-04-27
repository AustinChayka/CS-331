/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#include <climits>

using std::vector;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

std::vector<std::pair<int, int>> MinimaxPlayer::sucessors(OthelloBoard& b, char s) {

	std::vector<std::pair<int, int>> result;

	for(int col = 0; col < b.get_num_cols(); col++) for(int row = 0; row < b.get_num_rows(); row++) {

		if(b.is_legal_move(col, row, s)) {

			result.push_back(std::pair<int, int>(col, row));

		}

	}

	return result;

}

int MinimaxPlayer::utility(OthelloBoard& b) {

	int util = 0;

	for(int col = 0; col < b.get_num_cols(); col++) for(int row = 0; row < b.get_num_rows(); row++) {

		char c = b.get_cell(col, row);
		if(c == b.get_p2_symbol()) util--;
		else if(c == b.get_p1_symbol()) util++;

	}

	return util;

}

int MinimaxPlayer::minValue(OthelloBoard& b) {
	
	char s = b.get_p2_symbol();

	if(!b.has_legal_moves_remaining(s)) return utility(b);

	int v = INT_MAX;
	std::vector<std::pair<int, int>> nextMoves = sucessors(b, s);

	for(int i = 0; i < nextMoves.size(); i++) {
		OthelloBoard tB = b;
		tB.play_move((nextMoves.at(i)).first, (nextMoves.at(i)).second, s);
		v = std::min(v, maxValue(tB));
	}

	return v;

}

int MinimaxPlayer::maxValue(OthelloBoard& b) {
	
	char s = b.get_p1_symbol();

	if(!b.has_legal_moves_remaining(s)) return utility(b);

	int v = INT_MIN;
	std::vector<std::pair<int, int>> nextMoves = sucessors(b, s);

	for(int i = 0; i < nextMoves.size(); i++) {
		OthelloBoard tB = b;
		tB.play_move((nextMoves.at(i)).first, (nextMoves.at(i)).second, s);
		v = std::max(v, minValue(tB));
	}

	return v;

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