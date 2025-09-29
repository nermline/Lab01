#pragma once
#include "Board.h"
#include <string>

void experiment(Board& board, const int n, const int m, const int& repetitions);
void select_squares(const int& m, Board& board);
void save_to_csv_random(const Board& board, const std::string& filename);
void save_to_csv_dependence(const Board& board, const std::string& filename);
