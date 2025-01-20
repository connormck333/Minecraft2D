#include "../../include/blocks/GoldOre.h"

#include "../../include/inventory/items/GoldItem.h"

GoldOre::GoldOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(128, 128);
    sprite->setPosition(pos);
}

Item* GoldOre::getItem() const {
    return new GoldItem();
}