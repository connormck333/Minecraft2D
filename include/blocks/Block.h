#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include "../sprites/GroundSprite.h"
#include "utils/CollisionType.h"
#include "../inventory/items/Item.h"

class Block : public GameSprite {
private:
    bool isAir = false;

public:
    explicit Block(const std::string& fileName);

    Block();

    void loadBlock(int x, int y);

    CollisionType* collidesWith(GroundSprite* sprite) const;

    bool isBlockAir() const;

    virtual Item* getItem() const;
};

#endif //BLOCK_H
