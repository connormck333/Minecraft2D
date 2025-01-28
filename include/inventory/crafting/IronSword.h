#pragma once

#ifndef IRONSWORD_H
#define IRONSWORD_H

#include "./CraftItem.h"

class IronSword final : public CraftItem {
public:
    explicit IronSword();

    Item* getHotbarItem() override;
};

#endif //IRONSWORD_H
