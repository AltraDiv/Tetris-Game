#ifndef IBLOCK_H
#define IBLOCK_H

#include "block.h"


class IBlock: public Block {

  public:
    IBlock();
    void rotate() override;
    void counterRotate() override;
};

#endif
