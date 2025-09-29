#pragma once
#include <iostream>
#include <fstream>
#include "experiment.h"
#include "multiplicity.h"

using namespace std;
void select_squares(const int& m, Board& board) {
    for (int i = 0; i < m; i++) {
        board();
    }
}

void check_ofstream_is_open(const ofstream& ofstream, const string& filename) {
    if (!ofstream) {
        throw runtime_error("Cannot open file " + filename);
    }
}
void save_to_csv_random(const Board& board, const string& filename) {
    vector<int> squares = board.get_squares();
    ofstream out(filename);
    check_ofstream_is_open(out, filename);

    for (int i = 0; i < squares.size(); i++) {
        out << i << "," << squares[i] << endl;
    }
}

void save_to_csv_dependence(const int n, const vector<int>& ms, const int& repetitions, const string& filename) {
    ofstream out(filename);
    check_ofstream_is_open(out, filename);

    out << "m_ratio,avg_multiplicity,med_multiplicity" << endl;

    for (auto m : ms) {
        long double avg_sum = 0.0;
        long double med_sum = 0.0;

        for (int i = 0; i < repetitions; i++) {
            Board board(n);
            select_squares(m, board);

            avg_sum += average_multiplicity(board);
            med_sum += median_multiplicity(board);
        }

        double avg = avg_sum / repetitions;
        double med = med_sum / repetitions;
        double ratio = (double)m / n / n;

        out << ratio << "," << avg << "," << med << endl;
        cout << m << "," << ratio << "," << avg << "," << med << endl;
    }
}

void experiment(Board& board, const int n, const int m, const int& repetitions) {
    cout << "---- Start program experiment! ----" << endl;
    select_squares(m, board);
    save_to_csv_random(board, "output_random.csv");
    cout << "Results of random saved in 'random_check.csv'" << endl;

    vector<int> ms = { m / 5, m / 4, m / 3, m / 2, m, m * 2, m * 3, m * 4, m * 5};
    save_to_csv_dependence(n, ms, repetitions, "output_dependence.csv");
    cout << "Multiplicities dependence to m/n^2 saved to 'output_dependence.csv'" << endl;

}