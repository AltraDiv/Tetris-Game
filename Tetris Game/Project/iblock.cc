#include "iblock.h"
#include "board.h"
#include <exception>

const int i_default_pos[4][2] = {{2,0},{2,1},{2,2},{2,3}};

IBlock::IBlock()
    : Block(i_default_pos[0][1], i_default_pos[0][0], i_default_pos[1][1], i_default_pos[1][0], 
                        i_default_pos[2][1], i_default_pos[2][0], i_default_pos[3][1], i_default_pos[3][0], 'I'){}

void IBlock::rotate() {
    if (loc4_x != loc1_x) {
        loc4_x = loc1_x;
        loc3_x = loc1_x;
        loc2_x = loc1_x;
        loc4_y += 1;
        loc3_y += -1;
        loc2_y += -2;
    } else {
        loc4_y = loc1_y;
        loc3_y = loc1_y;
        loc2_y = loc1_y;
        loc4_x += 3;
        loc3_x += 2;
        loc2_x += 1;
    }
    
}
void IBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
