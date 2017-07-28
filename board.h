#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Board {

private:
    int columnCount, rowCount;
    int * board;
    int blockType, rotation;
    int offset = 0;
    int height = 0;
    int numIgn = 4;

private:

    void placeNum(int blockType, int rotation) {
        if (blockType == 1) {
            if (rotation == 1 || rotation == 3)
                { for (int i = 0; i < 4; i++) { board[rowCount * i + offset + height] = 2; }}
            else if (rotation == 2 || rotation == 4)
                { for (int i = 0; i < 4; i++) { board[i + offset + height] = 2; }}
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 2) {
            if (rotation == 1) {
                board[0 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i + offset + height] = 2; }
            }
            else if (rotation == 2) {
                board[1 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + offset + height] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount + 2 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[i + offset + height] = 2; }
            }
            else if (rotation == 4) {
                board[rowCount * 2 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1 + offset + height] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 3) {
            if (rotation == 1) {
                board[2 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i + offset + height] = 2; }
            }
            else if (rotation == 2) {
                board[rowCount * 2 + 1 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + offset + height] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[i + offset + height] = 2; }
            }
            else if (rotation == 4) {
                board[0 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1 + offset + height] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 4) {
            if (rotation == 1 || rotation == 2 || rotation == 3 || rotation == 4) {
                board[0 + offset + height] = 2;
                board[1 + offset + height] = 2;
                board[columnCount + offset + height] = 2;
                board[columnCount + 1 + offset + height] = 2;
            }
            else {
                    cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl;
            }
        }
        else if (blockType == 5) {
            if (rotation == 1 || rotation == 3) {
                board[1 + offset + height] = 2;
                board[2 + offset + height] = 2;
                board[rowCount + offset + height] = 2;
                board[rowCount + 1 + offset + height] = 2;
            }
            else if (rotation == 2 || rotation == 4) {
                board[0 + offset + height] = 2;
                board[rowCount + offset + height] = 2;
                board[rowCount +1 + offset + height] = 2;
                board[rowCount * 2 + 1 + offset + height] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 6) {
            if (rotation == 1) {
                board[1 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount + i + offset + height] = 2; }
            }
            else if (rotation == 2) {
                board[rowCount + 1 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + offset + height] = 2; }
            }
            else if (rotation == 3) {
                board[rowCount + 1 + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[i + offset + height] = 2; }
            }
            else if (rotation == 4) {
                board[rowCount + offset + height] = 2;
                for (int i = 0; i < 3; i++) { board[rowCount * i + 1 + offset + height] = 2; }
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 7) {
            if (rotation == 1 || rotation == 3) {
                board[0 + offset + height] = 2;
                board[1 + offset + height] = 2;
                board[rowCount + 1 + offset + height] = 2;
                board[rowCount + 2 + offset + height] = 2;
            }
            else if (rotation == 2 || rotation == 4) {
                board[1 + offset + height] = 2;
                board[rowCount + offset + height] = 2;
                board[rowCount + 1 + offset + height] = 2;
                board[rowCount * 2 + offset + height] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else { cerr << "ERROR::INVALID_NEW_BLOCKTYPE_VALUE" << endl; }
    }

public:

    Board(int columns, int rows) {
        if (columns > 0 && rows > 0) {
            columnCount = columns;
            rowCount = rows;
            board = new int[columnCount * rowCount];
            for (int i = 0; i < (rowCount * columnCount); i++) {
                board[i] = 0;
            }
        } else {
            cerr << "ERROR::BOARD_LENGTH_VALUES" << endl;
        }
    }

    void newBlock(int blockTypeT, int rotationT, bool centered = true) {
        blockType = blockTypeT;
        rotation = rotationT;
        offset = 0;
        height = 0 * columnCount;

        if (centered) {
            offset = columnCount / 2 - 1;
        }
        placeNum(blockType, rotation);
    }

    bool moveBlock(bool direction) {
        int subtractor = 0;
        if (blockType == 1 && (rotation == 1 || rotation == 3)) {
            subtractor = 1;
        }
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) { //this statement includes the square block
            subtractor = 4;
        }
        else if ((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                  && (rotation == 1 || rotation == 3)) {
            subtractor = 3;
        }
        else {
            subtractor = 2;
        }

        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2 && offset > 0 && offset < columnCount - subtractor) {
                board[i] = 0;
            }
        }

        if (direction && offset < columnCount - subtractor) {
            offset = offset + 1;
            placeNum(blockType, rotation);
        }
        else if (!direction && offset > 0) {
            offset = offset - 1;
            placeNum(blockType, rotation);
        }
        else {
                return false;
        }
        return true;
    }

    void dropBlock() {

        int subtractor;
        int blockCount = 0;
        int blockStore = 0;
        bool place = false;
        int * cloneBoard;

        if (blockType == 1 && (rotation == 1 || rotation == 3)) {
            subtractor = 4;
        }
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) {
            subtractor = 1;
        }
        else if (((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                 && (rotation == 1 || rotation == 3)) || (blockType == 4)) {
            subtractor = 2;
        }
        cloneBoard = new int[columnCount * rowCount];
        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) {
                board[i] = 0;
            }
            else if (board[i] == 1) {
                blockCount++;
            }
            cloneBoard[i] = board[i];
        }

        /*
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                int oned_index = (i * columnCount) + (j);
                cout << *(cloneBoard + oned_index) << " ";
            }
            cout << endl;
        }
        */

        height = columnCount * (rowCount - subtractor);

        while (!place) {

            placeNum(blockType, rotation);
            blockStore = 0;

            for (int i = 0; i < columnCount * rowCount; i++) {
                if (board[i] == 1) {
                    blockStore++;
                }
            }

            //cout << "blockCount is " << blockCount << ", blockStore is " << blockStore << endl;

            if (blockCount != blockStore) {
                height = height - columnCount;

                for (int i = 0; i < columnCount * rowCount; i++) {
                    board[i] = cloneBoard[i];
                }

            } else {
                place = true;
            }
        }

        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) {
                board[i] = 1;
            }
        }

    }

    bool checkGameOver() {
        for (int i = 0; i < columnCount * numIgn; i++) {
            if (board[i] == 1) { system("cls"); return true; }
            return false;
        }
    }

    int clearLine() {
        int clearTimes = 0;

        for (int i = columnCount*numIgn; i < columnCount*rowCount;) {
            
            int countI = 0;
            for (int j = 0; j < columnCount; j++) {
                if(board[i + j] == 1) { countI = countI + 1; }
            }

            if (countI == columnCount) {
                clearTimes++;
                int j = i;
                while (j > 0) {
                    for (int k = 0; k < columnCount; k++) {
                        board[j + k] = board[j + k - columnCount];
                    }
                    j = j - 1;
                }
                for (int n = 0; n < columnCount; n++) { board[n] = 0; }
            }
            i = i + columnCount;
        }

        return clearTimes;
    }

    void debugPrint() {
        system("cls");
        for (int i = 0; i < rowCount; i++) {
            cout << endl;
            for (int k = 0; k < columnCount; k++) {
                cout << board[i*columnCount + k] << " ";
            }
        }
        cout << endl;
    }
};

#endif // BOARD_H_INCLUDED
