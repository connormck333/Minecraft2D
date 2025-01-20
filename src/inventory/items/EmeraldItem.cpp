#include "../../../include/inventory/items/EmeraldItem.h"

#include "../../../include/Utils.h"

EmeraldItem::EmeraldItem() : Item("emerald", "emerald.png", false) {
    constexpr int height = 127;
    constexpr int width = 107;

    loadRect(26, 16, height, width);
    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
