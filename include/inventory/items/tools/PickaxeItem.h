#pragma once

#ifndef PICKAXEITEM_H
#define PICKAXEITEM_H

#include "../Item.h"

class PickaxeItem : public Item {
protected:
    int durability;
    int strength;

public:
    PickaxeItem(const std::string& id, const std::string& fileName, int durability, int strength);

    int getDurability() const;
    int getStrength() const;

    void weakenDurability(int weakness);
};

#endif //PICKAXEITEM_H
