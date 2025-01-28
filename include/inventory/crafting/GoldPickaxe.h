#pragma once

#ifndef GOLDPICKAXE_H
#define GOLDPICKAXE_H

#include "CraftItem.h"

class GoldPickaxe final : public CraftItem {
public:
    explicit GoldPickaxe();

    Item* getHotbarItem() override;
};

#endif // GOLDPICKAXE_H
