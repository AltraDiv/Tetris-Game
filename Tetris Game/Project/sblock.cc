#include "sblock.h"
#include <exception>

const int o_default_pos[4][2] = {{2,0},{2,1},{3,1},{3,2}};

SBlock::SBlock()
    : Block(o_default_pos[0][1], o_default_pos[0][0], o_default_pos[1][1], o_default_pos[1][0], 
                        o_default_pos[2][1], o_default_pos[2][0], o_default_pos[3][1], o_default_pos[3][0], 'S'){}

void SBlock::rotate() {
    bool stage_2 = false;
    if ((loc1_y == loc2_y) && (loc3_y == loc4_y) && (loc4_x == 2)) {
        loc1_x += 1;
        loc2_y += 1;
        loc3_x -= 1;
        loc4_y += 1;
        loc4_x -= 2;
        stage_2 = true;
    } else if ((loc2_y == loc3_y) && (loc1_x == 1) && (loc4_x == 0)) {
        loc4_x += 2;
        loc3_x += 1;
        loc3_y += 1;
        loc1_x -= 1;
        loc1_y += 1;
        stage_2 = false;
    } else if ((loc1_y == loc2_y) && (loc3_y == loc4_y) && (loc4_y == 2) && (loc4_x == 2)) {
        loc1_y -= 1;
        loc1_x += 1;
        loc3_x -= 1;
        loc3_y -= 1;
        loc4_x -= 2;
        loc1_y -= 2;
        loc2_y -= 2;
        loc3_y -= 2;
        loc4_y -= 2;
    } else {
        loc1_x -= 1;
        loc2_y -= 1;
        loc3_x += 1;
        loc4_x += 2;
        loc4_y -= 1;
        loc1_y -= 1;
        loc2_y -= 1;
        loc3_y -= 1;
        loc4_y -= 1;
    }
    
}
void SBlock::counterRotate() {
    rotate();
    rotate();
    rotate();
}
