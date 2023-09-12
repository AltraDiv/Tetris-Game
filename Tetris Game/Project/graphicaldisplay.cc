#include "graphicaldisplay.h"

GraphicalDisplay::GraphicalDisplay(Player *p1, Player *p2, Xwindow *wind): p1{p1}, p2{p2}, wind{wind}{}

void GraphicalDisplay::printBoard() {
    int color = 0;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            char c = p1->getBoard()->getBoard(i)[j];
            if (c == 'J') {
                color = wind->Blue;
            }
            else if (c == 'L') {
                color = wind->Green;
            }
            else if (c == 'O') {
                color = wind->Yellow;
            }
            else if (c == 'I') {
                color = wind->Cyan;
            }
            else if (c == 'S') {
                color = wind->Black;
            }
            else if (c == 'Z') {
                color = wind->Magenta;
            }
            else if (c == 'T') {
                color = wind->Orange;
            }
            else {
                color = wind->White;
            }
            wind->fillRectangle(j * 10, i * 10, 20, 20, color);
        }

        for (int j = 0; j < 11; ++j) {
            char c = p2->getBoard()->getBoard(i)[j];
            if (c == 'J') {
                color = wind->Blue;
            }
            else if (c == 'L') {
                color = wind->Green;
            }
            else if (c == 'O') {
                color = wind->Yellow;
            }
            else if (c == 'I') {
                color = wind->Cyan;
            }
            else if (c == 'S') {
                color = wind->Black;
            }
            else if (c == 'Z') {
                color = wind->Magenta;
            }
            else if (c == 'T') {
                color = wind->Orange;
            }
            wind->fillRectangle((j * 10) + 100, i * 10, 20, 20, color);
        }
    }
}

void GraphicalDisplay::printStartGame() {

}
