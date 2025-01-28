#pragma once

#ifndef SWORDITEM_H
#define SWORDITEM_H

#include "../Item.h"

class SwordItem : public Item {
protected:
    int durability;
    float damage;

public:
    SwordItem(const std::string& id, const std::string& fileName, int durability, float damage);

    int getDurability() const;
    float getDamage() const;
    void decreaseDurability(int weakness);
};

#endif //SWORDITEM_H
