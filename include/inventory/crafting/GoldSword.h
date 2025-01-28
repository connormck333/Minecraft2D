#pragma once

#ifndef GOLDSWORD_H
#define GOLDSWORD_H

#include "./CraftItem.h"

class GoldSword final : public CraftItem {
public:
    explicit GoldSword();

    Item* getHotbarItem() override;
};

#endif //GOLDSWORD_H
