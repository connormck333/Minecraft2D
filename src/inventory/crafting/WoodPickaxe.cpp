#include "../../../include/inventory/crafting/WoodPickaxe.h"
#include "../../../include/inventory/items/WoodItem.h"

WoodPickaxe::WoodPickaxe() : CraftItem("Wooden_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* wood = new WoodItem();
    wood->setQuantity(3);
    addRequirement(wood);
}
