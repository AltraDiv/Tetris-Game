#ifndef GRAPHDISPLAY_H
#define GRAPHDISPLAY_H
#include "display.h"
#include "player.h"
#include "window.h"

class GraphicalDisplay: public VisualDisplay{
    Player *p1;
    Player *p2;
    Xwindow *wind; 
  public:
    GraphicalDisplay(Player *p1, Player *p2, Xwindow *wind);
    void printBoard() override;
    void printStartGame() override;
};

#endif
