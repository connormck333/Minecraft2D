#include "../../include/blocks/DiamondOre.h"

#include "../../include/inventory/items/DiamondItem.h"

DiamondOre::DiamondOre(sf::Vector2f pos) : Block("blocks2.png", 3, 3) {
    loadBlock(64, 64);
    sprite->setPosition(pos);
}

Item* DiamondOre::getItem() const {
    return new DiamondItem();
}
