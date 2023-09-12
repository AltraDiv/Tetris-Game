#ifndef BLOCK_H
#define BLOCK_H

class Block {
  protected:
    const char letter;
    int loc1_x;
    int loc1_y;
    int loc2_x;
    int loc2_y;
    int loc3_x;
    int loc3_y;
    int loc4_x;
    int loc4_y;
  public:
    Block(int loc1_x, int loc1_y, int loc2_x, int loc2_y, int loc3_x, int loc3_y, int loc4_x, int loc4_y, char letter);
    int getloc1_x();
    int getloc1_y();
    int getloc2_x();
    int getloc2_y();
    int getloc3_x();
    int getloc3_y();
    int getloc4_x();
    int getloc4_y();
    const char getletter();
    void moveDown();
    void moveRight();
    void moveLeft();
    virtual void rotate() = 0;
    virtual void counterRotate() = 0;
    char getLetter();
};

#endif
