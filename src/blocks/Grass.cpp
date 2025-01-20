#include "../../include/blocks/Grass.h"

#include "../../include/inventory/items/DirtItem.h"

Grass::Grass(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 64);
    sprite->setPosition(pos);
}

Item* Grass::getItem() const {
    return new DirtItem();
}
