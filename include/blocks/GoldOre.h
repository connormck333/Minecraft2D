#pragma once

#ifndef GOLDORE_H
#define GOLDORE_H

#include "./Block.h"

class GoldOre : public Block {
public:
    explicit GoldOre(sf::Vector2f pos);

    Item *getItem() const override;
};

#endif //GOLDORE_H
