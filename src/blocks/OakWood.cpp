#include "../../include/blocks/OakWood.h"

#include "../../include/inventory/items/WoodItem.h"

OakWood::OakWood(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(192, 64);
    sprite->setPosition(pos);
}

Item* OakWood::getItem() const {
    return new WoodItem();
}
