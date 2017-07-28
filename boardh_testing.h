#ifndef BOARDH_TESTING_H_INCLUDED
#define BOARDH_TESTING_H_INCLUDED

#include "test_tools.h"
#include "board.h"

void attempt_square_newblock();

void attempt_two_newblocks();

void test_square_centering();

void proper_board_sizing();

void test_game_over_height();

void test_clear_2_lines_simul();



void run_tests(bool run_visual_tests = true);



#endif // BOARDH_TESTING_H_INCLUDED
