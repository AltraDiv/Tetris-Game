#ifndef PLAYER_H
#define PLAYER_H

#include "player.h"
#include "board.h"
#include "block.h"

class Player {
    Board *board;
    int level;
    int score;
    bool isheavy;
    bool isblind;
    bool isforce;
  public:
    Player(Board *board, int level, int score);
    void specialAction();
    Board *getBoard();
    int getLevel();
    int getScore();
    void levelUp();
    void levelDown();
    void addBlock(Block *blk);
    void addNxtBlk(Block *blk);
    void updateBoard();
    ~Player();
    bool getHeavy();
    bool getBlind();
    bool getForce();
};

#endif
