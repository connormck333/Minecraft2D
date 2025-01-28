#include "../../../../include/inventory/items/tools/IronPickaxeItem.h"
#include "../../../../include/Utils.h"

IronPickaxeItem::IronPickaxeItem() : PickaxeItem("iron_pickaxe", "CraftItems/Iron_Pickaxe.png", 55, 3) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
