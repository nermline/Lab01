// Compiler: g++ 13.3.0

#include <iostream>
#include <vector>
#include "Board.h"
#include "multiplicity.h"
#include "experiment.h"
using namespace std;

void check_value(int &value) {
    if (cin.fail()) throw invalid_argument("Invalid argument: Wrong Input!");
    if (value <= 0) throw invalid_argument("Value must be greater than zero!");
}
int enter_value() {
    int value;
    cin >> value;
    check_value(value);
    return value;
}

Board data_input(int& n, int& m) {
    cout << "Enter board side size: ";
    n = enter_value();
    Board board(n);
    cout << "Squares to choose amount: ";
    m = enter_value();
    return board;
}

void multiplicities_output(double &avg_multiplicity, double &med_multiplicity) {
    cout << endl;
    cout << "Done!" << endl;
    cout << "Average: " << avg_multiplicity << endl;
    cout << "Median: " << med_multiplicity << endl;
}

void start_experiment(Board& board, int& n, int& m) {
    save_to_csv(board, "output.csv");
    cout << "Enter amount of repetitions: ";
    int repetitions = enter_value();
    experiment(n, m, repetitions);
}
int main() {
    try {
        int n = 0, m = 0;
        Board board = data_input(n, m);
        select_squares(m, board);

        cout << "Calculating multiplicities..." << endl;

        double avg_multiplicity = average_multiplicity(board);
        double med_multiplicity = median_multiplicity(board);

        multiplicities_output(avg_multiplicity, med_multiplicity);

        cout << "Try program experiment? (1 - yes, 0 - no): ";
        int answer;
        cin >> answer;
        if (!cin.fail() && answer == 1) {
            start_experiment(board, n, m);
        }
        return 0;
    } 
    catch (const exception& e) {
        cout << e.what() << endl;
        return 1;
    }
}