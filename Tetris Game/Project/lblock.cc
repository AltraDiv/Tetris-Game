#include "lblock.h"
#include <exception>

const int l_default_pos[4][2] = {{3,0},{3,1},{3,2},{2,2}};

LBlock::LBlock()
    : Block(l_default_pos[0][1], l_default_pos[0][0], l_default_pos[1][1], l_default_pos[1][0], 
                        l_default_pos[2][1], l_default_pos[2][0], l_default_pos[3][1], l_default_pos[3][0], 'L'){}

void LBlock::rotate() {
    if ((loc1_y == loc2_y) && loc4_x == 2) {
        loc1_y -= 1;
        loc2_x -= 1;
        loc3_x -= 2;
        loc3_y += 1;
        loc4_y += 2;
        loc4_x -= 1;
    } else if ((loc1_x == loc2_x) && loc4_y == 2) {
        loc4_x -= 1;
        loc3_y -= 1;
        loc2_x += 1;
        loc1_x += 2;
        loc1_y += 1;
    } else if ((loc1_y == loc2_y) && loc4_x == 0) {
        loc4_y -= 2;
        loc3_x += 1;
        loc3_y -= 1;
        loc1_y += 1;
        loc1_x -= 1;
    } else {
        loc1_x -= 1;
        loc2_y += 1;
        loc3_x += 1;
        loc3_y += 2;
        loc4_x += 2;
        loc4_y += 1;
        loc1_y -= 1;
        loc2_y -= 1;
        loc3_y -= 1;
        loc4_y -= 1;
    }
}
void LBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
