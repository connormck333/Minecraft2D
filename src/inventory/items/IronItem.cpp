#include "../../../include/inventory/items/IronItem.h"
#include "../../../include/Utils.h"

IronItem::IronItem() : Item("iron", "iron.png", false) {
    constexpr int height = 275;
    constexpr int width = 359;

    loadRect(0, 42, height, width);
    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
