#include "zblock.h"
#include <exception>

const int o_default_pos[4][2] = {{2,1},{2,2},{3,0},{3,1}};

ZBlock::ZBlock()
    : Block(o_default_pos[0][1], o_default_pos[0][0], o_default_pos[1][1], o_default_pos[1][0], 
                        o_default_pos[2][1], o_default_pos[2][0], o_default_pos[3][1], o_default_pos[3][0], 'Z'){}

void ZBlock::rotate() {
    if ((loc1_y == loc2_y) &&  (loc4_y == 1 && loc4_x == 1)) {
        loc4_y += 1;
        loc4_x += 1;
        loc3_x += 2;
        loc2_x -= 1;
        loc2_y += 1;
    } else if ((loc1_x == loc2_x) && (loc4_y == 2 && loc4_x == 2)) {
        loc1_x -= 1;
        loc1_y += 2;
        loc2_y += 1;
        loc3_x -= 1;
        loc4_y -= 1;
    } else if ((loc3_y == loc4_y) && loc4_x == 2) {
        loc1_y -= 2;
        loc2_x -= 1;
        loc2_y -= 1;
        loc4_y += 1;
        loc4_x -= 1;
    } else if ((loc1_x == loc2_x)  && loc4_x == 1) {
        loc1_x += 1;
        loc2_y -= 1;
        loc2_x += 2;
        loc3_x -= 1;
        loc4_y -= 1;
    }
}
void ZBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
