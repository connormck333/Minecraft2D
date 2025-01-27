#pragma once

#ifndef IRONPICKAXE_H
#define IRONPICKAXE_H

#include "./CraftItem.h"

class IronPickaxe final : public CraftItem {
public:
    IronPickaxe();

    Item* getHotbarItem() override;
};

#endif //IRONPICKAXE_H
