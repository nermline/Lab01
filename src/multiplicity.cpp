#include "multiplicity.h"
#include <iostream>
#include <algorithm>

using namespace std;

double average_multiplicity(Board& board) {
	const auto squares_p = board.get_squares();
	double sum_of_multiplicities = 0.0;
	int total_board_size = squares_p.size();

	for (int i = 0; i < total_board_size; i++) {
		sum_of_multiplicities += squares_p[i];
	}

	return sum_of_multiplicities / total_board_size;
}

double median_multiplicity(Board& board) {
	const auto squares_p = board.get_squares();
	int total_board_size = squares_p.size();
	vector<int> sorted_squares = board.get_squares();

	sort(sorted_squares.begin(), sorted_squares.end());

	if (total_board_size % 2 == 1) {
		return sorted_squares[total_board_size / 2];
	}
	else {
		return (sorted_squares[total_board_size / 2 - 1] + sorted_squares[total_board_size / 2]) / 2.0;
	}

}

