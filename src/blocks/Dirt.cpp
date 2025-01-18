#include "../../include/blocks/Dirt.h"

#include "../../include/inventory/items/DirtItem.h"

Dirt::Dirt(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 128);
    sprite->setPosition(pos);
}

std::string Dirt::getItem() const {
    return "dirt";
}
