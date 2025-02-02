#pragma once

#ifndef DIRT_H
#define DIRT_H

#include "Block.h"

class Dirt: public Block {
public:
    Dirt(sf::Vector2f pos);

    Item* getItem() const override;
};

#endif //DIRT_H
