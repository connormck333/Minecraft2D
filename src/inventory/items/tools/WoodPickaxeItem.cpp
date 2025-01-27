#include "../../../../include/inventory/items/tools/WoodPickaxeItem.h"
#include "../../../../include/Utils.h"

WoodPickaxeItem::WoodPickaxeItem() : Item("wood_pickaxe", "CraftItems/Wooden_Pickaxe.png") {
    constexpr int height = 360;
    constexpr int width = 360;

    sprite->setScale(getItemScale(sprite->getScale(), height, width));
}
