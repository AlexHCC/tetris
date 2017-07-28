#include "boardh_testing.h"

void attempt_square_newblock() {
    Board board(20,20);

    board.newBlock(4, 3, true);

    board.debugPrint();
    prompt_visual_error("Does board look right after a new centered square block?",
                        "error (in attempt_one_newblock): board doesn't look right after one square newBlock");
}

void attempt_two_newblocks() {
    Board board(20,20);

    board.newBlock(4, 3, true);
    board.newBlock(5,3, true);

    board.debugPrint();
    prompt_visual_error("Does board show an error of some sort after two consecutive newBlocks?",
                        "error (in attempt_two_new_blocks): board doesn't show error after two consecutive newBlocks"\
                        " (causes weird printing)");
}


void test_square_centering() {
    for (int i = 9; i < 12; i++) {
        Board board(i,i);

        board.newBlock(4,3, true);

        board.debugPrint();

        prompt_visual_error("Is square block centered?",
                            "error (in test_square_centering): square block not centered in some board setup of size 9,10, 11");

    }

}

void test_game_over_height() {
    Board board(10,4);
    board.newBlock(4,4, true);
    board.dropBlock();
    board.debugPrint();

    if (!board.checkGameOver()) {
        report_error("error (in test_game_over_height): after square block drop in board of height 4"\
                     ", checkGameOver() didn't return true");
    }
}

void test_clear_2_lines_simul() {
    Board board(6,5);

    board.newBlock(4,4, true);
    board.moveBlock(false);
    board.moveBlock(false);
    board.dropBlock();

    board.newBlock(4,4, true);
    board.dropBlock();

    board.newBlock(4,4,true);
    board.moveBlock(true);
    board.moveBlock(true);
    board.dropBlock();

    board.clearLine();
    board.debugPrint();

    prompt_visual_error("Is the board completely of 0s?",
                        "error (in test_clear_line): 2 rows should've been cleared of lines"\
                        ", but not the case here");
}

void run_tests(bool run_visual_tests) {
    clear_debug_file();

    if (run_visual_tests) {
        attempt_square_newblock();
        attempt_two_newblocks();
        test_square_centering();
        test_clear_2_lines_simul();
    }

    test_game_over_height();
}
