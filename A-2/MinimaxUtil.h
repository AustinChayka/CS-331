#ifndef MINIMAXUTIL_H
#define MINIMAXUTIL_H

#include "OthelloBoard.h"
#include <vector>

std::vector<std::pair<int, int>> sucessors(OthelloBoard& b, char s);
int utility(OthelloBoard& b);
int minValue(OthelloBoard& b);
int maxValue(OthelloBoard& b);

#endif