#include "../../include/blocks/Dirt.h"

#include "../../include/inventory/items/DirtItem.h"

Dirt::Dirt(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 128);
    sprite->setPosition(pos);
}

Item* Dirt::getItem() const {
    return new DirtItem();
}
