#ifndef TEST_TOOLS_H_INCLUDED
#define TEST_TOOLS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void open_ofile(const char* file_name, ofstream& res_file, ios_base::openmode open_mode);

const char* get_newline_or_blank(bool get_newline);

void file_append_line(const char* file_name, const char* text_line, bool pre_newline = false, bool post_newline = false);

void close_ofile(ofstream& res_file);

void clear_file(const char* file_name);

void clear_debug_file();

bool prompt_yes_or_no(const char* input_prompt, const char* yes_option, const char* no_option);

void append_to_debug_file(const char* message);

void report_error(const char* error_message, bool log_message = true);

void prompt_visual_error(const char* prompt, const char* error_message, bool log_message = true);

#endif // TEST_TOOLS_H_INCLUDED
