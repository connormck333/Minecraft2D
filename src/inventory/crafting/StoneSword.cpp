#include "../../../include/inventory/crafting/StoneSword.h"
#include "../../../include/inventory/items/StoneItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/swords/StoneSwordItem.h"

StoneSword::StoneSword() : CraftItem("stone_sword", "Stone_Sword.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    // Add requirements
    auto* stone = new StoneItem();
    stone->setQuantity(2);
    addRequirement(stone);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* StoneSword::getHotbarItem() {
    return new StoneSwordItem();
}
