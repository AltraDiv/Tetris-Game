#include "oblock.h"
#include <exception>

const int o_default_pos[4][2] = {{2,0},{2,1},{3,0},{3,1}};

OBlock::OBlock()
    : Block(o_default_pos[0][1], o_default_pos[0][0], o_default_pos[1][1], o_default_pos[1][0], 
                        o_default_pos[2][1], o_default_pos[2][0], o_default_pos[3][1], o_default_pos[3][0], 'O'){}

void OBlock::rotate() {
    return;
}
void OBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
