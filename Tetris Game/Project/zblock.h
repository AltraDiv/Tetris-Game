#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "block.h"

class ZBlock: public Block {

  public:
    ZBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
