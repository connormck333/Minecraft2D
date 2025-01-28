#include "../../../../include/inventory/items/tools/GoldPickaxeItem.h"
#include "../../../../include/Utils.h"

GoldPickaxeItem::GoldPickaxeItem() : PickaxeItem("gold_pickaxe", "CraftItems/Golden_Pickaxe.png", 32, 6) {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
