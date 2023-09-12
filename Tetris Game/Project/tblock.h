#ifndef TBLOCK_H
#define TBLOCK_H

#include "block.h"

class TBlock: public Block {

  public:
    TBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
