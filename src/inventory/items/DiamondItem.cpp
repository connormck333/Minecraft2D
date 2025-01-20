#include "../../../include/inventory/items/DiamondItem.h"
#include "../../../include/Utils.h"

DiamondItem::DiamondItem() : Item("diamond", "diamond.png", false) {
    constexpr int height = 137;
    constexpr int width = 127;

    loadRect(16, 16, height, width);
    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
