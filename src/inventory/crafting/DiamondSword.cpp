#include "../../../include/inventory/crafting/DiamondSword.h"
#include "../../../include/inventory/items/DiamondItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/swords/DiamondSwordItem.h"

DiamondSword::DiamondSword() : CraftItem("diamond_sword", "Diamond_Sword.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* diamond = new DiamondItem();
    diamond->setQuantity(2);
    addRequirement(diamond);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* DiamondSword::getHotbarItem() {
    return new DiamondSwordItem();
}
