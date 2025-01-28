#pragma once

#ifndef DIAMONDPICKAXE_H
#define DIAMONDPICKAXE_H

#include "CraftItem.h"

class DiamondPickaxe final : public CraftItem {
public:
    explicit DiamondPickaxe();

    Item* getHotbarItem() override;
};

#endif // DIAMONDPICKAXE_H
