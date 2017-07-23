#include "debug_tools.h"

void debug_msg(const char * details) {
    cout << "DEBUG MESSAGE" << endl;
    cout << "DETAILS: " << details << endl;
    cout << "Enter a random integer to continue" << endl;
    int random;
    cin >> random;
}
