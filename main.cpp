#include <iostream>
#include "board.h"
#include "debug_tools.h"

using namespace std;

void debug_stop(Board& board) {
    cout << "debug break here" << endl;
    board.debugPrint();
    int random = 0;
    cin >> random;
}

void original_main() {
    cout << "\033[1;31m" << " Welcome to tetris!" << "\033[0m" << endl;
    cout << "" << endl;
    cout << " ■ ■ ■" << endl;
    cout << " ■" << endl;

    Board board(20, 20);
    board.newBlock(4, 3, true);
    board.moveBlock(true);
    board.moveBlock(true);

    board.dropBlock();
    board.newBlock(4, 3, true);
    board.moveBlock(true);
    //board.moveBlock(true);
    //
    board.dropBlock();

    board.debugPrint();
}

void custom_main() {
    cout << "\033[1;31m" << " Welcome to tetris!" << "\033[0m" << endl;
     cout << "" << endl;
    cout << " ■ ■ ■" << endl;
    cout << " ■" << endl;

    Board board(8, 4);

    //debug_stop(board);

    board.newBlock(4, 3, true);

    for (int i = 0; i < 40; i++) {
        board.moveBlock(true);
    }

    debug_stop(board);

    board.dropBlock();

    //debug_stop(board);

    board.newBlock(4, 3, true);
    board.moveBlock(true);

    debug_stop(board);

    board.dropBlock();

    board.debugPrint();
}

int main()
{
    original_main();
    //custom_main();
    return 0;
}
