#include "../../../include/inventory/items/GoldItem.h"

#include "../../../include/Utils.h"

GoldItem::GoldItem() : Item("gold", "gold.png", false) {
    constexpr int height = 150;
    constexpr int width = 159;

    loadRect(0, 3, height, width);
    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
