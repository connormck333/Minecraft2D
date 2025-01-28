#include "../../../include/inventory/crafting/DiamondPickaxe.h"
#include "../../../include/inventory/items/DiamondItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/tools/DiamondPickaxeItem.h"

DiamondPickaxe::DiamondPickaxe() : CraftItem("diamond_pickaxe", "Diamond_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* diamond = new DiamondItem();
    diamond->setQuantity(3);
    addRequirement(diamond);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* DiamondPickaxe::getHotbarItem() {
    return new DiamondPickaxeItem();
}
