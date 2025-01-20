#include "../../../include/inventory/items/DirtItem.h"
#include "../../../include/blocks/Dirt.h"
#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

DirtItem::DirtItem() : Item("dirt", "blocks2.png") {
    loadRect(0, 128, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
    sprite->setScale(getItemBlockScale(sprite->getScale()));
}

Block* DirtItem::createBlock(const sf::Vector2f& pos) {
    return new Dirt(pos);
}
