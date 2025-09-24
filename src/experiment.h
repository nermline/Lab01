#pragma once
#include "Board.h"

void experiment(int n, int m, int repetitions);
void select_squares(int m, Board& board);
void save_to_csv(Board& board, const string& filename);