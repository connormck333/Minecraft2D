#include "../../../include/inventory/crafting/GoldSword.h"
#include "../../../include/inventory/items/GoldItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/swords/GoldSwordItem.h"

GoldSword::GoldSword() : CraftItem("gold_sword", "Golden_Sword.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* gold = new GoldItem();
    gold->setQuantity(2);
    addRequirement(gold);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* GoldSword::getHotbarItem() {
    return new GoldSwordItem();
}
