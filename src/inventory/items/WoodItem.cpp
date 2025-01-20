#include "../../../include/inventory/items/WoodItem.h"

#include "../../../include/Constants.h"
#include "../../../include/Utils.h"
#include "../../../include/blocks/OakWood.h"

WoodItem::WoodItem() : Item("wood", "blocks2.png") {
    loadRect(192, 64, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
    sprite->setScale(getItemBlockScale(sprite->getScale()));
}

Block* WoodItem::createBlock(const sf::Vector2f& pos) {
    return new OakWood(pos);
}
