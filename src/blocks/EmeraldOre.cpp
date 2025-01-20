#include "../../include/blocks/EmeraldOre.h"

#include "../../include/inventory/items/EmeraldItem.h"

EmeraldOre::EmeraldOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(64, 128);
    sprite->setPosition(pos);
}

Item* EmeraldOre::getItem() const {
    return new EmeraldItem();
}
