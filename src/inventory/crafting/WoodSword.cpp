#include "../../../include/inventory/crafting/WoodSword.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/swords/WoodSwordItem.h"

WoodSword::WoodSword() : CraftItem("wood_sword", "Wooden_Sword.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* WoodSword::getHotbarItem() {
    return new WoodSwordItem();
}
