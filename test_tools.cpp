#include "test_tools.h"

const char * const debug_file_name = "debug_results.txt";

void open_ofile(const char * file_name, ofstream& file, ios_base::openmode open_mode) {
    file.open(file_name, open_mode);

    if (!file.is_open()) {
        cerr << "error (in open_file) file open unsuccessful (" << file_name <<
        "), throwing int error" << endl;
        throw -1;
    }
}

const char* get_newline_or_blank(bool get_newline) {
    if (get_newline) {
        return "\n";
    } else {
        return "";
    }
}

void file_append_line(const char* file_name, const char* text_line, bool pre_newline, bool post_newline) {
    ofstream res_file;
    open_ofile(file_name, res_file, ios::out | ios::app);

    const char* pre_newline_text = get_newline_or_blank(pre_newline);
    const char* post_newline_text = get_newline_or_blank(post_newline);

    res_file << pre_newline_text << text_line << post_newline_text;

    close_ofile(res_file);
}

void close_ofile(ofstream& file) {
    file.close();
}

void clear_file(const char* file_name) {
    ofstream res_file;
    res_file.open(file_name, ios::out | ios::trunc);
    res_file.close();
}

void clear_debug_file() {
    clear_file(debug_file_name);
}

bool prompt_yes_or_no(const char* input_prompt, const char* yes_option, const char* no_option) {
    bool result = false;
    string input = "";

    cout << endl;
    while (true) { //if used yes_option/no_option check but one of them is "", while loop would never
            //start at all
        cout << input_prompt << " (" << yes_option << "/" <<
        no_option << "): ";
        getline(cin, input);

        if (input == yes_option) {
            result = true;
            break;
        } else if (input == no_option) {
            result = false;
            break;
        } else {
            cout << "invalid input, try again" << endl;
            input = "";
        }
    }

    return result;
}

void append_to_debug_file(const char* message) {
    file_append_line(debug_file_name, message, true, true);
}

void report_error(const char* error_message, bool log_message) {
    cout << endl << error_message << endl;
    if (log_message == true) {
        append_to_debug_file(error_message);
    }
}

void prompt_visual_error(const char* prompt, const char* error_message, bool log_message) {
    bool result = prompt_yes_or_no(prompt, "Y", "N");

    if (result != true) {
        report_error(error_message, log_message);
    }
}
