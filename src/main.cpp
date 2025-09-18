#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Board board(20);
    board.print();
    for(int i; i < 100; i++) {
        board();
    }
    cout << endl;
    board.print();
    return 0;
}