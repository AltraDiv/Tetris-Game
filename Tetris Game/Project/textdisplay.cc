#include "textdisplay.h"
#include "player.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(Player *p1, Player *p2): p1{p1}, p2{p2}{}

void TextDisplay::printBoard() {
    cout << "Player 1:                                   Player 2:" << endl;
    cout << "Level:     " << p1->getLevel() << "                                 " << "Level:     " << p2->getLevel() << endl;
    cout << "Score:     " << p1->getScore() << "                                 " << "Score:     " << p2->getScore() << endl; 
    cout << "-----------                                 -----------" << endl;  
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            cout << p1->getBoard()->getBoard(i)[j];
        }
        cout << "                                 ";
        for (int j = 0; j < 11; ++j) {
            cout << p2->getBoard()->getBoard(i)[j];
        }
        cout << endl;
    }
    cout << "-----------                                 -----------" << endl;
    cout << "Next Block:                                 Next Block:  ";
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << p1->getBoard()->getNxtBrd(i)[j];
        }
        cout << "                                        ";
        for (int j = 0; j < 4; ++j) {
            cout << p2->getBoard()->getNxtBrd(i)[j];
        }
        cout << endl;
    }
}

void TextDisplay::printStartGame() {
    
}
