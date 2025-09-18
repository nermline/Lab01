#include <vector>
#include <iostream>
#include <random>

class Board {
    private:
        const int n;
        const int squares_amount;
        std::vector<int> squares;
        std::mt19937 gen;
        std::uniform_int_distribution<int> dist;

    public:
        Board(int n);
        void operator()();

        void print();
};