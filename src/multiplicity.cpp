#pragma once
#include "multiplicity.h"
#include <iostream>
#include <algorithm>

using namespace std;

double average_multiplicity(Board &board) {
	const vector<int> squares_p = board.get_squares();
	const int total_board_size = squares_p.size();
	double sum_of_multiplicities = 0.0;

	for (int i = 0; i < total_board_size; i++) {
		sum_of_multiplicities += squares_p[i];
	}

	return sum_of_multiplicities / total_board_size;
}

double median_multiplicity(Board& board) {
	vector<int> sorted_squares = board.get_squares();
	const int total_board_size = sorted_squares.size();
	sort(sorted_squares.begin(), sorted_squares.end());

	if (total_board_size % 2 == 1) {
		return sorted_squares[total_board_size / 2];
	}
	else {
		return (sorted_squares[total_board_size / 2 - 1] + sorted_squares[total_board_size / 2]) / 2.0;
	}

}

