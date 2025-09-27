#pragma once
#include <iostream>
#include <fstream>
#include "experiment.h"
#include "multiplicity.h"

using namespace std;

void save_to_csv(Board& board, const string& filename) {
    auto squares = board.get_squares();
    ofstream out(filename);
    for (int i = 0; i < (int)squares.size(); i++) {
        out << i << "," << squares[i] << "\n";
    }
}

void select_squares(int& m, Board& board) {
    for (int i = 0; i < m; i++) {
        board();
    }
}

void exp_results_output(int& n, int& m, int& repetitions, long double& avg_sum, long double& med_sum) {
    cout << endl;
    cout << "Average over " << repetitions << " runs: " << avg_sum / repetitions << endl;
    cout << "Median over " << repetitions << " runs: " << med_sum / repetitions << endl;
    cout << "m/n^2: " << (double)m / n / n << endl;
}

void experiment(int& n, int& m, int& repetitions) {
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