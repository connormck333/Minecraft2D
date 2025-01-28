#include "../../../../include/inventory/items/swords/StoneSwordItem.h"
#include "../../../../include/Utils.h"

StoneSwordItem::StoneSwordItem() : SwordItem("stone_sword", "CraftItems/Stone_Sword.png", 30, 1.3f) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
