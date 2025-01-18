#include "../../include/blocks/Grass.h"

Grass::Grass(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 64);
    sprite->setPosition(pos);
}

std::string Grass::getItem() const {
    return "dirt";
}
