#include "../../include/blocks/IronOre.h"
#include "../../include/inventory/items/IronItem.h"

IronOre::IronOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(192, 128);
    sprite->setPosition(pos);
}

Item* IronOre::getItem() const {
    return new IronItem();
}
