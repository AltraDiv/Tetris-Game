#ifndef LBLOCK_H
#define LBLOCK_H

#include "block.h"

class LBlock: public Block {

  public:
    LBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
