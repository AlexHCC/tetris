#include <iostream>

#include "board.h"
#include "boardh_testing.h"

using namespace std;

int main() {
    //run_tests(true);
    clear_debug_file();
    test_clear_2_lines_simul();
    test_game_over_height();

    /*
    Board board(20, 20);

    board.newBlock(4, 3, true);

    board.moveBlock(true);
    board.moveBlock(true);

    board.dropBlock();
    board.newBlock(2, 1, true);
    board.moveBlock(true);

    board.dropBlock();

    if (board.checkGameOver()) {
        cout << "Game over" << endl;
        return 0;
    }

    board.clearLine();
    board.debugPrint();
    */

    return 0;
}
