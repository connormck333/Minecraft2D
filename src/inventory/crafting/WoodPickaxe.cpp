#include "../../../include/inventory/crafting/WoodPickaxe.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/tools/WoodPickaxeItem.h"

WoodPickaxe::WoodPickaxe() : CraftItem("wood_pickaxe", "Wooden_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* wood = new WoodItem();
    wood->setQuantity(3);
    addRequirement(wood);
}

Item* WoodPickaxe::getHotbarItem() {
    return new WoodPickaxeItem();
}
