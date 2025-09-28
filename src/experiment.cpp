#include <iostream>
#include <fstream>
#include "experiment.h"
#include "multiplicity.h"

using namespace std;

void save_to_csv(const Board& board, const string& filename) {
    auto squares = board.get_squares();
    ofstream out(filename);
    if (!out) {
        throw runtime_error("Cannot open file " + filename);
    }

    for (int i = 0; i < (int)squares.size(); i++) {
        out << i << "," << squares[i] << "\n";
    }
}

void select_squares(const int& m, Board& board) {
    for (int i = 0; i < m; i++) {
        board();
    }
}

void exp_results_output(const int& n,const int& m, const int& repetitions, const long double& avg_sum, const long double& med_sum) {
    cout << endl;
    cout << "Average over " << repetitions << " runs: " << avg_sum / repetitions << endl;
    cout << "Median over " << repetitions << " runs: " << med_sum / repetitions << endl;
    cout << "m/n^2: " << (double)m / n / n << endl;
}

void experiment(const int& n, const int& m, const int& repetitions) {
    cout << "---- Start program experiment! ----" << endl;

    long double avg_sum = 0.0;
    long double med_sum = 0.0;

    for (int i = 1; i <= repetitions; i++) {
        Board board(n);
        select_squares(m, board);

        double avg = average_multiplicity(board);
        double med = median_multiplicity(board);

        avg_sum += avg;
        med_sum += med;

        cout << "Run #" << i << ": average=" << avg << ", median=" << med << endl;
    }
    exp_results_output(n, m, repetitions, avg_sum, med_sum);
}