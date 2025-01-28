#include "../../include/blocks/GoldOre.h"

#include "../../include/inventory/items/GoldItem.h"

GoldOre::GoldOre(sf::Vector2f pos) : Block("blocks2.png", 3, 2) {
    loadBlock(128, 128);
    sprite->setPosition(pos);
}

Item* GoldOre::getItem() const {
    return new GoldItem();
}