#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>

using namespace std;

class Board {

private:
    int columnCount, rowCount;
    int * board;

public:

    Board(int columns, int rows) {
        if (columns > 0 && rows > 0) {
            columnCount = columns;
            rowCount = rows;

            board = new int[columnCount * rowCount];
            for (int i = 0; i < columnCount; i++) {
                board[i] = 0; }
        } else { cerr << "ERROR::BOARD_LENGTH_VALUES" << endl; }
    }

    void newBlock(int blockType, int rotation, bool centered = true) {
        if (blockType == 1) {
            if (rotation == 1 || rotation == 3)
                { for (int i = 0; i < 4; i++) { board[rowCount * i] = 2; }}
            else if (rotation == 2 || rotation == 4)
                { for (int i = 0; i < 4; i++) { board[i] = 2; }}
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 2) {
            if (rotation == 1) {
                board[0] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i] = 2; }
            }
            else if (rotation == 2) {
                board[1] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount + 2] = 2;
                for (int i = 0; i < 3; i++) { board[i] = 2; }
            }
            else if (rotation == 4) {
                board[rowCount * 2] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 3) {
            if (rotation == 1) {
                board[2] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i] = 2; }
            }
            else if (rotation == 2) {
                board[rowCount * 2 + 1] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount] = 2;
                for (int i = 0; i < 3; i++) { board[i] = 2; }
            }
            else if (rotation == 4) {
                board[0] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 4) {
            if (rotation == 1 || rotation == 2 || rotation == 3 || rotation == 4) {
                board[0] = 2;
                board[1] = 2;
                board[rowCount] = 2;
                board[rowCount + 1] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 5) {
            if (rotation == 1 || rotation == 3) {
                board[1] = 2;
                board[2] = 2;
                board[rowCount] = 2;
                board[rowCount + 1] = 2;
            }
            else if (rotation == 2 || rotation == 4) {
                board[0] = 2;
                board[rowCount] = 2;
                board[rowCount +1] = 2;
                board[rowCount * 2 + 1] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 6) {
            if (rotation == 1) {
                board[1] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i] = 2; }
            }
            else if (rotation == 2) {
                board[rowCount + 1] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount + 1] = 2;
                for (int i = 0; i < 3; i++) { board[i] = 2; }
            }
            else if (rotation == 4) {
                board[rowCount] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 7) {
            if (rotation == 1 || rotation == 3) {
                board[0] = 2;
                board[1] = 2;
                board[rowCount + 1] = 2;
                board[rowCount + 2] = 2;
            }
            else if (rotation == 2 || rotation == 4) {
                board[1] = 2;
                board[rowCount] = 2;
                board[rowCount + 1] = 2;
                board[rowCount * 2] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else { cerr << "ERROR::INVALID_NEW_BLOCKTYPE_VALUE" << endl; }
    }

    void debugPrint() {
        system("clear");

        for (int i = 0; i < columnCount; i++) {
            cout << endl;
            for (int k = 0; k < rowCount; k++) {
                cout << board[rowCount * i + k] << " ";
            }
        }
    }
};

#endif // BOARD_H_INCLUDED
