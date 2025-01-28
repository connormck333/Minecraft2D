#include "../../../../include/inventory/items/tools/WoodPickaxeItem.h"
#include "../../../../include/Utils.h"

WoodPickaxeItem::WoodPickaxeItem() : PickaxeItem("wood_pickaxe", "CraftItems/Wooden_Pickaxe.png", 15, 1) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
