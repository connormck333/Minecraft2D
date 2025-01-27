#include "../../../include/inventory/crafting/IronPickaxe.h"

#include "../../../include/inventory/items/IronItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/tools/IronPickaxeItem.h"

IronPickaxe::IronPickaxe() : CraftItem("iron_pickaxe", "Iron_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    auto* iron = new IronItem();
    iron->setQuantity(3);
    addRequirement(iron);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* IronPickaxe::getHotbarItem() {
    return new IronPickaxeItem();
}
