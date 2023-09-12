#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "display.h"
#include "player.h"
class TextDisplay : public VisualDisplay{
    Player *p1;
    Player *p2;
  public:
    TextDisplay(Player *p1, Player *p2);
    void printBoard() override;
    void printStartGame() override;
};

#endif
