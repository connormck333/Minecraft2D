#pragma once

#ifndef STONEITEM_H
#define STONEITEM_H

#include "./Item.h"

class StoneItem : public Item {
public:
    StoneItem(int slotId);

    Block* createBlock(const sf::Vector2f &pos) override;
};

#endif //STONEITEM_H
