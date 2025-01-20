#pragma once

#ifndef WOODITEM_H
#define WOODITEM_H

#include "./Item.h"

class WoodItem : public Item {
public:
    WoodItem(int slotId);

    Block* createBlock(const sf::Vector2f &pos) override;
};

#endif //WOODITEM_H
