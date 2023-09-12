#include "jblock.h"
#include <exception>

const int j_default_pos[4][2] = {{2,0},{3,0},{3,1},{3,2}};

JBlock::JBlock()
    : Block(j_default_pos[0][1], j_default_pos[0][0], j_default_pos[1][1], j_default_pos[1][0], 
                        j_default_pos[2][1], j_default_pos[2][0], j_default_pos[3][1], j_default_pos[3][0], 'J'){}

void JBlock::rotate() {
    if ((loc1_y != loc2_y) && (loc4_x != 0)) {
        loc1_x += 1;
        loc2_y -= 1;
        loc3_x -= 1;
        loc4_y += 1;
        loc4_x -= 2;
    } else if (loc1_y == loc2_y && (loc1_x > 0)) {
        loc1_x += 1;
        loc1_y += 2;
        loc2_x += 2;
        loc2_y += 1;
        loc3_x += 1;
        loc4_y -= 1;
    } else if ((loc1_x == loc2_x) && loc1_x > 0) {
        loc4_y -= 1;
        loc4_x += 1;
        loc1_x -= 2;
        loc2_y += 1;
        loc2_x -= 1;
    } else if ((loc2_x == loc3_x && (loc1_x == 0))) {
        loc1_y -= 1;
        loc2_x -= 1;
        loc3_y += 1;
        loc4_x += 1;
        loc4_y += 2;
        loc1_y -= 1;
        loc2_y -= 1;
        loc3_y -= 1;
        loc4_y -= 1;
    }
}


void JBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
