#include "../../include/blocks/Stone.h"

#include "../../include/inventory/items/StoneItem.h"

Stone::Stone(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(128, 64);
    sprite->setPosition(pos);
}

Item* Stone::getItem() const {
    return new StoneItem();
}
