#ifndef OBLOCK_H
#define OBLOCK_H

#include "block.h"

class OBlock: public Block {

  public:
    OBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
