#include "../../../../include/inventory/items/tools/DiamondPickaxeItem.h"
#include "../../../../include/Utils.h"

DiamondPickaxeItem::DiamondPickaxeItem() : PickaxeItem("diamond_pickaxe", "CraftItems/Diamond_Pickaxe.png", 1561, 4) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
