#include "../../../../include/inventory/items/swords/WoodSwordItem.h"
#include "../../../../include/Utils.h"

WoodSwordItem::WoodSwordItem() : SwordItem("wood_sword", "CraftItems/Wooden_Sword.png", 20, 1.0f) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
