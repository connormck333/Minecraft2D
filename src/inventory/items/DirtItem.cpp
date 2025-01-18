#include "../../../include/inventory/items/DirtItem.h"

#include "../../../include/Constants.h"

DirtItem::DirtItem(int slotId) : Item("dirt", slotId, "blocks2.png") {
    loadRect(0, 128, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);

    sf::Vector2f scale = sprite->getScale();
    scale.x = (scale.x / Constants::BLOCK_SIZE) * Constants::HOTBAR_SLOT_SIZE;
    scale.y = (scale.y / Constants::BLOCK_SIZE) * Constants::HOTBAR_SLOT_SIZE;
    sprite->setScale(scale);
}
