#include "../../include/blocks/OakWood.h"

OakWood::OakWood(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(192, 64);
    sprite->setPosition(pos);
}

std::string OakWood::getItem() const {
    return "wood";
}
