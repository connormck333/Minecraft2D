#include "../../../../include/inventory/items/tools/StonePickaxeItem.h"
#include "../../../../include/Utils.h"

StonePickaxeItem::StonePickaxeItem() : PickaxeItem("stone_pickaxe", "CraftItems/Stone_Pickaxe.png", 30, 2) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
