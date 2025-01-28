#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include "../sprites/GroundSprite.h"
#include "utils/CollisionType.h"
#include "../inventory/items/Item.h"

class Block : public GameSprite {
private:
    bool isAir = false;
    int pickaxeLevel = 0;
    int pickaxeDamage = 0;

public:
    explicit Block(const std::string& fileName);
    Block(const std::string& fileName, int pickaxeLevel, int pickaxeDamage);
    Block();

    void loadBlock(int x, int y);

    CollisionType* collidesWith(GroundSprite* sprite) const;

    [[nodiscard]] bool isBlockAir() const;
    [[nodiscard]] int getPickaxeLevel() const;
    [[nodiscard]] int getPickaxeDamage() const;

    virtual Item* getItem() const;
};

#endif //BLOCK_H
