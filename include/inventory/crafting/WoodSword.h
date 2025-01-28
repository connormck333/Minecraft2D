#pragma once

#ifndef WOODSWORD_H
#define WOODSWORD_H

#include "./CraftItem.h"

class WoodSword final : public CraftItem {
public:
    explicit WoodSword();

    Item* getHotbarItem() override;
};

#endif //WOODSWORD_H
