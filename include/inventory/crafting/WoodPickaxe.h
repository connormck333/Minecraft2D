#pragma once

#ifndef WOODPICKAXE_H
#define WOODPICKAXE_H

#include "CraftItem.h"

class WoodPickaxe final : public CraftItem {
public:
    explicit WoodPickaxe();

    Item* getHotbarItem() override;
};

#endif //WOODPICKAXE_H
