#pragma once

#ifndef STONESWORD_H
#define STONESWORD_H

#include "./CraftItem.h"

class StoneSword final : public CraftItem {
public:
    explicit StoneSword();

    Item* getHotbarItem() override;
};

#endif //STONESWORD_H
