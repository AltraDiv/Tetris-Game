#include "board.h"
#include <iostream>
#include "block.h"
using namespace std;

Board::Board() {
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            nxtBlkBoard[i][j] = ' ';
        }
    }
}
char *Board::getBoard(int row) {
    return board[row];
}
char *Board::getNxtBrd(int row) {
    return nxtBlkBoard[row];
}
void Board::setBlock(Block *player_blk) {
    blk = player_blk;
}
Block *Board::getBlock() {
    return blk;
}
void Board::setNextBlock(Block *player_blk) {
    nxtblk = player_blk;
}
Block *Board::getNextBlock() {
    return nxtblk;
}
void Board::addBlock() {
    board[blk->getloc1_y()][blk->getloc1_x()] = blk->getletter();
    board[blk->getloc2_y()][blk->getloc2_x()] = blk->getletter();
    board[blk->getloc3_y()][blk->getloc3_x()] = blk->getletter();
    board[blk->getloc4_y()][blk->getloc4_x()] = blk->getletter();
}

void Board::addNxtBlk() {
    nxtBlkBoard[nxtblk->getloc1_y()][nxtblk->getloc1_x()] = nxtblk->getletter();
    nxtBlkBoard[nxtblk->getloc2_y()][nxtblk->getloc2_x()] = nxtblk->getletter();
    nxtBlkBoard[nxtblk->getloc3_y()][nxtblk->getloc3_x()] = nxtblk->getletter();
    nxtBlkBoard[nxtblk->getloc4_y()][nxtblk->getloc4_x()] = nxtblk->getletter();
}

void Board::dropBlock() {
    board[blk->getloc1_y()][blk->getloc1_x()] = ' ';
    board[blk->getloc2_y()][blk->getloc2_x()] = ' ';
    board[blk->getloc3_y()][blk->getloc3_x()] = ' ';
    board[blk->getloc4_y()][blk->getloc4_x()] = ' ';
    while (blk->getloc1_y() != 17 && board[blk->getloc1_y() + 1][blk->getloc1_x()] == ' ' && blk->getloc2_y() != 17 && board[blk->getloc2_y() + 1][blk->getloc2_x()] == ' ' &&
            blk->getloc3_y() != 17 && board[blk->getloc3_y() + 1][blk->getloc3_x()] == ' '  && blk->getloc4_y() != 17 && board[blk->getloc4_y() + 1][blk->getloc4_x()] == ' ') {
        blk->moveDown();
    }
    board[blk->getloc1_y()][blk->getloc1_x()] = blk->getletter();
    board[blk->getloc2_y()][blk->getloc2_x()] = blk->getletter();
    board[blk->getloc3_y()][blk->getloc3_x()] = blk->getletter();
    board[blk->getloc4_y()][blk->getloc4_x()] = blk->getletter();
}
void Board::clearNxtBlock() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            nxtBlkBoard[i][j] = ' ';
        }
    }
}

void Board::removeOldPos() {
    board[blk->getloc1_y()][blk->getloc1_x()] = ' ';
    board[blk->getloc2_y()][blk->getloc2_x()] = ' ';
    board[blk->getloc3_y()][blk->getloc3_x()] = ' ';
    board[blk->getloc4_y()][blk->getloc4_x()] = ' ';
}

void Board::clearRow(int row) {
    for (int i = row; i > 0; --i) {
        for (int j = 0; j < 11; ++j) {
            board[i][j] = board[i - 1][j];
        }
    }
}
bool Board::checkLine(int row) {
    for (int i = 0; i < 11; ++i) {
        if (board[row][i] == ' ') {
            return false;
        }
    }
    return true;
}

bool Board::checkCollision() {
    int x_1 = blk->getloc1_x();
    int x_2 = blk->getloc2_x();
    int x_3 = blk->getloc3_x();
    int x_4 = blk->getloc4_x();

    int y_1 = blk->getloc1_y();
    int y_2 = blk->getloc2_y();
    int y_3 = blk->getloc3_y();
    int y_4 = blk->getloc4_y();
    
    int most_right_x = x_1;
    int most_right_y = y_1;

    int most_left_x = x_1;
    int most_left_y = y_1;

    int most_down_y = y_1;
    int most_down_x = x_1;

    if (x_2 >= x_1 && x_2 >= x_3 && x_2 >= x_4) {
        most_right_x = x_2;
        most_right_y = y_2;
    }
    else if (x_3 >= x_1 && x_3 >= x_2 && x_3 >= x_4) {
        most_right_x = x_3;
        most_right_y = y_3;
        
    }
    else if (x_4 >= x_1 && x_4 >= x_2 && x_4 >= x_3) {
        most_right_x = x_4;
        most_right_y = y_4;
    }
    
    if (x_2 <= x_1 && x_2 <= x_3 && x_2 <= x_4) {
        most_left_x = x_2;
        most_left_y = y_2;
    }
    else if (x_3 <= x_1 && x_3 <= x_2 && x_3 <= x_4) {
        most_left_x = x_3;
        most_left_y = y_3;
    }
    else if (x_4 <= x_1 && x_4 <= x_2 && x_4 <= x_3) {
        most_left_x = x_4;
        most_left_y = y_4;
    }

    if (y_2 >= y_1 && y_2 >= y_3 && y_2 >= y_4) {
        most_down_x = x_2;
        most_down_y = y_2;
    }
    else if (y_3 >= y_1 && y_3 >= y_2 && y_3 >= y_4) {
        most_down_x = x_3;
        most_down_y = y_3;
    }
    else if (y_4 >= y_1 && y_4 >= y_3 && y_4 >= y_3) {
        most_down_x = x_4;
        most_down_y = y_4;
    }

    if (board[most_right_y][most_right_x + 1] != ' ' || board[most_down_y + 1][most_down_x] != ' ' ||
        board[most_left_y][most_left_x - 1] != ' ') {
        return true;
    } else if (most_down_y == 17) {
        return true;
    }else {
        return false;
    }
}
