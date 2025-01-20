#pragma once

#ifndef IRON_H
#define IRON_H

#include "./Block.h"

class IronOre : public Block {
public:
    explicit IronOre(sf::Vector2f pos);

    Item *getItem() const override;
};

#endif //IRON_H
