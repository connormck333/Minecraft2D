#pragma once

#ifndef OAKWOOD_H
#define OAKWOOD_H

#include "./Block.h"

class OakWood : public Block {
public:
    OakWood(sf::Vector2f pos);

    Item* getItem() const override;
};

#endif //OAKWOOD_H
