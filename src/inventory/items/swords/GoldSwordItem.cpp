#include "../../../../include/inventory/items/swords/GoldSwordItem.h"
#include "../../../../include/Utils.h"

GoldSwordItem::GoldSwordItem() : SwordItem("gold_sword", "CraftItems/Gold_Sword.png", 30, 1.8f) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
