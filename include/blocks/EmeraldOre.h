#pragma once

#ifndef EMERALDORE_H
#define EMERALDORE_H

#include "./Block.h"

class EmeraldOre : public Block {
public:
    explicit EmeraldOre(sf::Vector2f pos);

    Item* getItem() const override;
};

#endif //EMERALDORE_H
