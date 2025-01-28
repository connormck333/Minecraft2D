#include "../../../../include/inventory/items/swords/DiamondSwordItem.h"
#include "../../../../include/Utils.h"

DiamondSwordItem::DiamondSwordItem() : SwordItem("diamond_sword", "CraftItems/Diamond_Sword.png", 75, 2.3f) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
