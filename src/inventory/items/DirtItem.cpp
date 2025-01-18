#include "../../../include/inventory/items/DirtItem.h"

#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

DirtItem::DirtItem(int slotId) : Item("dirt", slotId, "blocks2.png") {
    loadRect(0, 128, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
    sprite->setScale(getItemBlockScale(sprite->getScale()));
}
