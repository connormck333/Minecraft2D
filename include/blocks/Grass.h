#pragma once

#ifndef GRASS_H
#define GRASS_H

#include "Block.h"

class Grass : public Block {
public:
    explicit Grass(sf::Vector2f pos);
};

#endif //GRASS_H
