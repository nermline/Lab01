// Compiler: g++ 13.3.0

#include <iostream>
#include <vector>
#include "Board.h"
#include "multiplicity.h"

using namespace std;

int enter_value() {
    int value;
    cin >> value;
    if (cin.fail()) throw invalid_argument("Invalid argument: Wrong Input!");
    if (value <= 0) throw invalid_argument("Value must be greater than zero!");
    return value;
}

void select_squares(int m, Board board) {
    for(int i = 0; i < m; i++) {
        board();
    }
}

int main() {
    cout << "Enter board side size: ";
    int n = enter_value();
    Board board(n);
    cout << "Squares to choose amount: ";
    int m = enter_value();
    select_squares(m, board);

    double average = average_multiplicity(board);
    cout << "Average: " << average << endl << endl;

    double median = median_multiplicity(board);
    cout << "Median: " << median << endl;

    return 0;
}