#include "../../../include/inventory/items/WoodItem.h"

#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

WoodItem::WoodItem(int slotId) : Item("wood", slotId, "blocks2.png") {
    loadRect(192, 64, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
    sprite->setScale(getItemBlockScale(sprite->getScale()));
}
