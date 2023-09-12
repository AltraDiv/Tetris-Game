#include "player.h"
#include "board.h"
#include "block.h"
#include <iostream>
using namespace std;

Player::Player(Board *board, int level, int score): board{board}, level{level}, score{score} {}
Board *Player::getBoard() {
    return board;
}
int Player::getLevel() {
    return level;
}
int Player::getScore() {
    return score;
}
void Player::levelUp(){
    ++level;
}
void Player::levelDown(){
     --level;
}

Player::~Player() {}
void Player::addBlock(Block *blk) {
    board->setBlock(blk);
    board->addBlock();
}
void Player::addNxtBlk(Block *blk) {
    board->setNextBlock(blk);
    board->addNxtBlk();
}
bool Player::getBlind() {
    return isblind;
}
bool Player::getHeavy() {
    return isheavy;
}
bool Player::getForce() {
    return isforce;
}
void Player::specialAction() {
    cout << "Enter Special Action:" << endl;
    string command;
    cin >> command;
    if (command == "blind") {

    }
    else if (command == "heavy") {

    }
    else if (command == "force") {

    }
}
void Player::updateBoard() {
    int counter = 0;
    for (int i = 3; i < 18; ++i) {
        if(board->checkLine(i)) {
            ++counter;
            board->clearRow(i);
        }
    }
    if (counter > 1) {
        specialAction();
    }
    score = (counter + level) + (counter + level);
}
