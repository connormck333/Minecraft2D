#pragma once

#ifndef DIAMONDORE_H
#define DIAMONDORE_H

#include "./Block.h"

class DiamondOre : public Block {
public:
    explicit DiamondOre(sf::Vector2f pos);

    Item* getItem() const override;
};

#endif //DIAMONDORE_H
