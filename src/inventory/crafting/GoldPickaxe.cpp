#include "../../../include/inventory/crafting/GoldPickaxe.h"
#include "../../../include/inventory/items/GoldItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/tools/GoldPickaxeItem.h"

GoldPickaxe::GoldPickaxe() : CraftItem("gold_pickaxe", "Golden_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* gold = new GoldItem();
    gold->setQuantity(3);
    addRequirement(gold);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* GoldPickaxe::getHotbarItem() {
    return new GoldPickaxeItem();
}
