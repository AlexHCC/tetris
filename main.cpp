#include <iostream>
#include "board.h"

using namespace std;

int main()
{
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
    return 0;
}
