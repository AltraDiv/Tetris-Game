#include "block.h"

//Test blah

// testing first push (ka3chaud)
Block::Block(int loc1_x, int loc1_y, int loc2_x, int loc2_y, int loc3_x, int loc3_y, int loc4_x, int loc4_y, char letter ):
 loc1_x{loc1_x}, loc1_y{loc1_y}, loc2_x{loc2_x}, loc2_y{loc2_y},
loc3_x{loc3_x}, loc3_y{loc3_y}, loc4_x{loc4_x}, loc4_y{loc4_y}, letter{letter}{}

int Block::getloc1_x() {
    return loc1_x;
}

int Block::getloc1_y() {
    return loc1_y;
}

int Block::getloc2_x() {
    return loc2_x;
}

int Block::getloc2_y() {
    return loc2_y;
}

int Block::getloc3_x() {
    return loc3_x;
}

int Block::getloc3_y() {
    return loc3_y;
}

int Block::getloc4_x() {
    return loc4_x;
}

int Block::getloc4_y() {
    return loc4_y;
}

const char Block::getletter() {
    return letter;
}

void Block::moveRight() {
    if (loc1_x != 10 && loc2_x != 10 && loc3_x != 10 && loc4_x != 10) { 
        ++loc1_x;
        ++loc2_x;
        ++loc3_x;
        ++loc4_x;
    }
}

void Block::moveLeft() {
    if (loc1_x != 0 && loc2_x != 0 && loc3_x != 0 && loc4_x != 0) {
        --loc1_x;
        --loc2_x;
        --loc3_x;
        --loc4_x;
    }
}

void Block::moveDown() {
    if (loc1_y != 17 && loc2_y != 17 && loc3_y != 17 && loc4_y != 17) {
        ++loc1_y;
        ++loc2_y;
        ++loc3_y;
        ++loc4_y;
    }
}
