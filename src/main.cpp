#include <iostream>
#include <vector>
#include "Board.h"
#include "experiment.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board board(15);
    board.print();
    for(int i = 0; i < 100; i++) {
        board();
    }
    cout << endl;
    board.print();

    cout << "test average: ";
    double average = average_multiplicity(board);
    cout << average << endl;

    cout << "test median: ";
    double median = median_multiplicity(board);
    cout << "\n median: " << median << endl;
    return 0;
}