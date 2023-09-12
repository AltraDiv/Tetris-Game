#ifndef BOARD_H
#define BOARD_H
#include "block.h"
using namespace std;

class Board {
    char board[18][11];
    char nxtBlkBoard[4][4];
    Block *blk;
    Block *nxtblk;
  public:
    Board();
    char *getBoard(int row);
    char *getNxtBrd(int row);
    Block *getBlock();
    void setBlock(Block *blk);
    Block *getNextBlock();
    void setNextBlock(Block *blk);
    void addBlock();
    void addNxtBlk();
    void dropBlock();
    void clearNxtBlock();
    void removeOldPos();
    void clearRow(int row);
    bool checkLine(int row);
    bool checkCollision();
};


#endif
