#include "../../../../include/inventory/items/swords/IronSwordItem.h"
#include "../../../../include/Utils.h"

IronSwordItem::IronSwordItem() : SwordItem("iron_sword", "CraftItems/Iron_Sword.png", 50, 1.7f) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
