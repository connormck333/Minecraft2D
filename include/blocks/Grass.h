#pragma once

#ifndef GRASS_H
#define GRASS_H

#include "Block.h"

class Grass : public Block {
public:
    explicit Grass(sf::Vector2f pos);

    Item* getItem() const override;
};

#endif //GRASS_H
