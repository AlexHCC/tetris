#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Board {

private: //Variables
    int columnCount, rowCount; //Storing vars
    int * board; //The board array
    int blockType, rotation;
    int offset = 0;
    int height = 0;

private:
    void placeNum(int blockType, int rotation) { //This is a funct that places a selected block with a selected rotation on the top left grid corner
        if (blockType == 1) { //The block type 1 is the straight line. Here it places it on the top left corner of the grid
            if (rotation == 1 || rotation == 3)
                { for (int i = 0; i < 4; i++) { board[rowCount * i + offset + height] = 2; }} //Sets the active block location cells to 2
            else if (rotation == 2 || rotation == 4)
                { for (int i = 0; i < 4; i++) { board[i + offset + height] = 2; }}
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; }
        }
        else if (blockType == 2) { //Another tetris block
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
            else { cerr << "ERROR::INVALID_BLOCKTYPE_ROTATION_VALUE" << endl; } //Prints err if rotation not found
        }
        else if (blockType == 3) { //Guesed it, just another tetris block..
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
        else { cerr << "ERROR::INVALID_NEW_BLOCKTYPE_VALUE" << endl; } //Prints err if block not found
    }

public: //Funcs accessed from main()

    Board(int columns, int rows) { //Creates a new board
        if (columns > 0 && rows > 0) {
            columnCount = columns;
            rowCount = rows;
            board = new int[columnCount * rowCount]; //Inits the arr
            //for (int i = 0; i < columnCount; i++) {
                //board[i] = 0; } //error (it's only columnCount here, should be rowCount
            for (int i = 0; i < (rowCount * columnCount); i++) {
                board[i] = 0;
            }
        } else { cerr << "ERROR::BOARD_LENGTH_VALUES" << endl; }
    }

    //Creates a new block
    void newBlock(int blockTypeT, int rotationT, bool centered = true) {
        //Reseting values with eatch new block
        blockType = blockTypeT;
        rotation = rotationT;
        offset = 0;
        height = 0;

        if (centered) { offset = rowCount / 2 - 1; } //If centered sets sthe spawn to the board center insteaad of the top left corner
        placeNum(blockType, rotation); //Calls the func that changes the array values that are equal with the block type to 2
    }

    //Moves the block. Very difficult to figure it out by yourself, so commented it to explain it better
    bool moveBlock(bool direction) {
        int subtractor; //The subtractor is what doesn't allow the block to move out of the board left and right.
        if (blockType == 1 && (rotation == 1 || rotation == 3)) {subtractor = 1;}
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) {subtractor = 4;}
        else if ((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                  && (rotation == 1 || rotation == 3)) {subtractor = 3;}
        else {subtractor = 2;}

        //All it does it increases the int offset by 1 or -1 depending the dir.
        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2 && offset > 0 && offset < rowCount - subtractor) { board[i] = 0; }
        }
        if (direction && offset < rowCount - subtractor) { offset = offset + 1; placeNum(blockType, rotation); }
        else if (!direction && offset > 0) { offset = offset - 1; placeNum(blockType, rotation); }
        else { return false; }
        return true;
    }

    void dropBlock() {

        int subtractor; //The same purpose as moveblock, only this time is made to prevent falling after the end of the board in the height axis
        int blockCount = 0; //You will understad those values later on, keep reading..
        int blockStore = 0;
        bool place = false;
        int * cloneBoard;

        //Seting up the falling prevention
        if (blockType == 1 && (rotation == 1 || rotation == 3)) {
                subtractor = 4;
        }
        else if (blockType == 1 && (rotation == 2 || rotation == 4)) {
                subtractor = 1;
        }
        else if (((blockType == 2 || blockType == 3 || blockType == 5 || blockType == 6 || blockType == 7)
                 && (rotation == 1 || rotation == 3)) //Warning found (parentheses): looks like this if statement is:
                 //1. if block is not the square one and its rotation is such that it's 2 units high
                 //2. or if it's the square block (it has to be 2 units high, regardless of rotation
                 || (blockType == 4)) {
                      subtractor = 2;
                      }
        else {
                subtractor = 3;
        }

        cloneBoard = new int[columnCount * rowCount];
        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) {
                    board[i] = 0;
            } //Sets all the cells containing the active block value from 2 to 0, since it will drop, so no longer there.
            else if (board[i] == 1) {
                    blockCount++;
            } //Counts the current non active cells.
            cloneBoard[i] = board[i]; //Copys the bloard arr to a clone.
        }

        /*
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) {
                int oned_index = (i * rowCount) + (j);
                cout << *(cloneBoard + oned_index) << " ";
            }
            cout << endl;
        }*/

        height = rowCount * (columnCount - subtractor); //Sets the block height as low as possible

        while (!place) {
            placeNum(blockType, rotation); // And then places the block at that height
            for (int i = 0; i < columnCount * rowCount; i++) {
                if (board[i] == 1) { blockStore++; } //Counts the inactive blocks after the drop
            }
            if (blockCount != blockStore) { height = height - rowCount; // If less it means we replaced some, so we should try mowing it up once
                for (int i = 0; i < columnCount * rowCount; i++) {
                    board[i] = cloneBoard[i]; ///Reseting the arr to its original copy //If commented out, no segment fault. //If i < the cell where the last 1 (inactive block) is, then no segfault
                }//And trys to see if it still hits a block

            } else { place = true; } //If not it exits

        }


        for (int i = 0; i < columnCount * rowCount; i++) {
            if (board[i] == 2) { board[i] = 1; } //Makes the avtive block inactive
        }

    }

    void debugPrint() { //Prints board
        system("cls");
        cout << "========DEBUG BOARD PRINT START===========" << endl;
        for (int i = 0; i < columnCount; i++) {
            cout << endl;
            for (int k = 0; k < rowCount; k++) {
                cout << board[rowCount * i + k] << " ";
            }
        }
        cout << endl;
        cout << "========DEBUG BOARD PRINT END===========" << endl;
    }
};

#endif // BOARD_H_INCLUDED
