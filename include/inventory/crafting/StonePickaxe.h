#pragma once

#ifndef STONEPICKAXE_H
#define STONEPICKAXE_H

#include "./CraftItem.h"

class StonePickaxe final : public CraftItem {
public:
    explicit StonePickaxe();

    Item* getHotbarItem() override;
};

#endif //STONEPICKAXE_H
