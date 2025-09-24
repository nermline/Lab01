#include "Board.h"

using namespace std;

Board::Board(int n) : squares_amount(n*n), squares(squares_amount, 0), 
                    n(n), gen(random_device{}()), dist(0, squares_amount - 1) {}

void Board::operator()() {
    squares[dist(gen)]++;
}

void Board::print() {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << squares[row * n + col] << " ";
        }
    cout << endl;
    }
}