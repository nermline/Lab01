// Compiler: g++ 13.3.0

#include <iostream>
#include <vector>
#include "Board.h"
#include "multiplicity.h"
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
    try {
        cout << "Enter board side size: ";
        int n = enter_value();
        Board board(n);
        cout << "Squares to choose amount: ";
        int m = enter_value();
        select_squares(m, board);
        
        double average = average_multiplicity(board);
        cout << "Average: " << average << endl;
        
        double median = median_multiplicity(board);
        cout << "Median: " << median << endl;
        
        cout << "Try program experiment? (1 - yes, 0 - no): ";
        int unswer;
        cin >> unswer;
        if (cin.fail() || unswer != 1) {
            return 0;
        } else {
            save_to_csv(board, "output.csv");

            cout << "Enter amount of repetitions: ";
            int repetitions = enter_value();
            experiment(n, m, repetitions);   
        }

        return 0;
    } catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}