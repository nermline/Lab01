#include <iostream>

#include "multiplicity.h"

using namespace std;

void experiment(int n, int m, Board board) {
    double average = average_multiplicity(board);
    cout << "Average: " << average << endl << endl;

    double median = median_multiplicity(board);
    cout << "Median: " << median << endl;

for(int i = 0; i < m; i++) {
        board();
    }
    cout << endl;


    
    double result  = m / n / (double)n;
    cout << "m/n^2 = " << (double)m / (n * n) << endl;
    cout << "Result: " << result << endl;

}