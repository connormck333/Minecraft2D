#include "../../../../include/inventory/items/swords/SwordItem.h"

SwordItem::SwordItem(const std::string &id, const std::string &fileName, const int durability, const float damage)
    : Item(id, fileName), durability(durability), damage(damage) {}

int SwordItem::getDurability() const {
    return durability;
}

float SwordItem::getDamage() const {
    return damage;
}

void SwordItem::decreaseDurability(const int weakness) {
    this->durability -= weakness;
}
