#pragma once

#ifndef DIAMONDSWORD_H
#define DIAMONDSWORD_H

#include "./CraftItem.h"

class DiamondSword final : public CraftItem {
public:
    explicit DiamondSword();

    Item* getHotbarItem() override;
};

#endif //DIAMONDSWORD_H
