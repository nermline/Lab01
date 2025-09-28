#pragma once
#include "Board.h"

using namespace std;

Board::Board(int n) :
    n(n),
    squares_amount(n*n),
    squares(squares_amount, 0),
    gen(random_device{}()),
    dist(0, squares_amount - 1) {}

void Board::operator()() {
    squares[dist(gen)]++;
}
