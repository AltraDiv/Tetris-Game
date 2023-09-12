#ifndef SBLOCK_H
#define SBLOCK_H

#include "block.h"

class SBlock: public Block {

  public:
    SBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
