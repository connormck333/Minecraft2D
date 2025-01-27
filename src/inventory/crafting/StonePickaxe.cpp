#include "../../../include/inventory/crafting/StonePickaxe.h"
#include "../../../include/inventory/items/StoneItem.h"
#include "../../../include/inventory/items/WoodItem.h"
#include "../../../include/inventory/items/tools/StonePickaxeItem.h"

StonePickaxe::StonePickaxe() : CraftItem("stone_pickaxe", "Stone_Pickaxe.png") {
    sprite.value().setScale(sf::Vector2f(0.25, 0.25));

    auto* stone = new StoneItem();
    stone->setQuantity(3);
    addRequirement(stone);

    auto* wood = new WoodItem();
    wood->setQuantity(2);
    addRequirement(wood);
}

Item* StonePickaxe::getHotbarItem() {
    return new StonePickaxeItem();
}
