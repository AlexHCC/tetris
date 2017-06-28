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
    board.newBlock(6, 4);
    board.debugPrint();
    return 0;
}
