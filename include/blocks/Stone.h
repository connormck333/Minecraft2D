#pragma once

#ifndef STONE_H
#define STONE_H

#include "Block.h"

class Stone : public Block {
public:
    Stone(sf::Vector2f pos);

    std::string getItem() const override;
};

#endif //STONE_H
