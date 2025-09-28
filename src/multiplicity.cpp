#pragma once
#include "multiplicity.h"
#include <iostream>
#include <algorithm>

using namespace std;

double average_multiplicity(const Board &board) {
	const vector<int> squares_p = board.get_squares();
	const int total_board_size = squares_p.size();
	double sum_of_multiplicities = 0.0;

	for (int i = 0; i < total_board_size; i++) {
		sum_of_multiplicities += squares_p[i];
	}

	return sum_of_multiplicities / total_board_size;
}

double median_multiplicity(const Board& board) {
	vector<int> squares_to_sort = board.get_squares();
	const int total_board_size = squares_to_sort.size();
	sort(squares_to_sort.begin(), squares_to_sort.end());

	if (total_board_size % 2 == 1) {
		return squares_to_sort[total_board_size / 2];
	}
	else {
		return (squares_to_sort[total_board_size / 2 - 1] + squares_to_sort[total_board_size / 2]) / 2.0;
	}

}

