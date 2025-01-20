#include "../../../include/inventory/items/StoneItem.h"

#include "../../../include/Constants.h"
#include "../../../include/Utils.h"
#include "../../../include/blocks/Stone.h"

StoneItem::StoneItem(int slotId) : Item("stone", slotId, "blocks2.png") {
    loadRect(128, 64, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
    sprite->setScale(getItemBlockScale(sprite->getScale()));
}

Block* StoneItem::createBlock(const sf::Vector2f& pos) {
    return new Stone(pos);
}