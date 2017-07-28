#include <iostream>
#include "board.h"

using namespace std;

void moveBlock(Board &board, int numOfTimes, bool direction) {
    for (int i = 0; i < numOfTimes; i++) {
        board.moveBlock(direction);
    }
}

int main() {

    Board board(10, 10);

    board.newBlock(4, 3, false);
    board.dropBlock();

    board.newBlock(4, 3, false);
    moveBlock(board, 2, true);
    board.dropBlock();

    board.newBlock(4, 3, false);
    moveBlock(board, 4, true);
    board.dropBlock();

    board.newBlock(4, 3, false);
    moveBlock(board, 6, true);
    board.dropBlock();

    board.newBlock(4, 3, false);
    moveBlock(board, 8, true);
    board.dropBlock();

    if (board.checkGameOver()) {
        cout << "Game over" << endl;
        return 0;
    }

    board.clearLine();
    board.debugPrint();

    return 0;
}
