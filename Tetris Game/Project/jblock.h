#ifndef JBLOCK_H
#define JBLOCK_H

#include "block.h"

class JBlock: public Block {
  public:
    JBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
