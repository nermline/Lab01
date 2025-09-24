// Compiler: g++ 13.3.0

#include <iostream>
#include <vector>
#include "Board.h"
#include "experiment.h"

using namespace std;

int enter_value() {
    int value;
    cin >> value;
    if (cin.fail()) throw invalid_argument("Invalid argument: Wrong Input!");
    if (value <= 0) throw invalid_argument("Value must be greater than zero!");
    return value;
}

int main() {
    cout << "Enter board side size: ";
    int n = enter_value();
    Board board(n);
    cout << "Squares to choose amount: ";
    int m = enter_value();
    experiment(n, m, board);
    return 0;
}