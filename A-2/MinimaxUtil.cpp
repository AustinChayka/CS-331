#include "MinimaxUtil.h"
#include <climits>

std::vector<std::pair<int, int>> sucessors(OthelloBoard& b, char s) {

	std::vector<std::pair<int, int>> result;

	for(int col = 0; col < b.get_num_cols(); col++) for(int row = 0; row < b.get_num_rows(); row++) {

		if(b.is_legal_move(col, row, s)) {

			result.push_back(std::pair<int, int>(col, row));

		}

	}

	return result;

}

int utility(OthelloBoard& b) {

	int util = 0;

	for(int col = 0; col < b.get_num_cols(); col++) for(int row = 0; row < b.get_num_rows(); row++) {

		char c = b.get_cell(col, row);
		if(c == b.get_p2_symbol()) util--;
		else if(c == b.get_p1_symbol()) util++;

	}

	return util;

}

int minValue(OthelloBoard& b) {
	
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

int maxValue(OthelloBoard& b) {
	
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