#include "../../../../include/inventory/items/tools/PickaxeItem.h"

PickaxeItem::PickaxeItem(const std::string& id, const std::string& fileName, const int durability, const int strength)
    : Item(id, fileName), durability(durability), strength(strength) {}

int PickaxeItem::getDurability() const {
    return durability;
}

int PickaxeItem::getStrength() const {
    return strength;
}

void PickaxeItem::weakenDurability(const int weakness) {
    durability -= weakness;
}
