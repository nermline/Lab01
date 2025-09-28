#pragma once
#include "Board.h"
#include <string>

void experiment(const int& n, const int& m, const int& repetitions);
void select_squares(const int& m, Board& board);
void save_to_csv(const Board& board, const std::string& filename);