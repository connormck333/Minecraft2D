#include "../../../include/inventory/crafting/IronSword.h"
#include "../../../include/inventory/items/IronItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/swords/IronSwordItem.h"

IronSword::IronSword() : CraftItem("iron_sword", "Iron_Sword.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* iron = new IronItem();
    iron->setQuantity(2);
    addRequirement(iron);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* IronSword::getHotbarItem() {
    return new IronSwordItem();
}
