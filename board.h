#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Board {

private:
    int columnCount, rowCount;
    int * board;
    int blockType, rotation;
    int offset = 0;
    int height = 0;

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
                board[rowCount + offset + height] = 2;
                board[rowCount + 1 + offset + height] = 2;
            }
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
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
            for (int i = 0; i < columnCount; i++) {
                board[i] = 0; }
        } else { cerr << "ERROR::BOARD_LENGTH_VALUES" << endl; }
    }

    void newBlock(int blockTypeT, int rotationT, bool centered = true) {
        blockType = blockTypeT;
        rotation = rotationT;
        offset = 0;
        height = 0;

        if (centered) { offset = rowCount / 2 - 1; }
        placeNum(blockType, rotation);
    }

    bool moveBlock(bool direction) {
        int subtractor;
        if (blockType == 1 && (rotation == 1 || rotation == 3)) {subtractor = 1;}
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) {subtractor = 4;}
        else if ((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                  && (rotation == 1 || rotation == 3)) {subtractor = 3;}
        else {subtractor = 2;}

        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2 && offset > 0 && offset < rowCount - subtractor) { board[i] = 0; }
        }
        if (direction && offset < rowCount - subtractor) { offset = offset + 1; placeNum(blockType, rotation); }
        else if (!direction && offset > 0) { offset = offset - 1; placeNum(blockType, rotation); }
        else { return false; }
        return true;
    }

    void dropBlock() {

        int subtractor;
        int blockCount = 0;
        int blockStore = 0;
        bool place = false;
        int * cloneBoard;

        if (blockType == 1 && (rotation == 1 || rotation == 3)) {subtractor = 4;}
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) {subtractor = 1;}
        else if ((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                  && (rotation == 1 || rotation == 3) || (blockType == 4)) {subtractor = 2;}
        else {subtractor = 3;}

        cloneBoard = new int[columnCount * rowCount];
        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) { board[i] = 0; }
            else if (board[i] == 1) { blockCount++; }
            cloneBoard[i] = board[i];
        }


        height = rowCount * (columnCount - subtractor);

        while (!place) {
            placeNum(blockType, rotation);
            for (int i = 0; i < columnCount * rowCount; i++) {
                if (board[i] == 1) { blockStore++; }
            }
            if (blockCount != blockStore) { height = height - rowCount;
                for (int i = 0; i < columnCount * rowCount; i++) {
                    board[i] = cloneBoard[i];
                }

            } else { place = true; }

        }


        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) { board[i] = 1; }
        }

    }

    void debugPrint() {
        system("cls");

        for (int i = 0; i < columnCount; i++) {
            cout << endl;
            for (int k = 0; k < rowCount; k++) {
                cout << board[rowCount * i + k] << " ";
            }
        }
    }
};

#endif // BOARD_H_INCLUDED
