#include "../../include/blocks/Stone.h"

Stone::Stone(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(128, 64);
    sprite->setPosition(pos);
}

std::string Stone::getItem() const {
    return "stone";
}
