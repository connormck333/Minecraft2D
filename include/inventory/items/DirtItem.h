#pragma once

#ifndef DIRTITEM_H
#define DIRTITEM_H

#include "./Item.h"

class DirtItem : public Item {
public:
    DirtItem();

    Block* createBlock(const sf::Vector2f &pos) override;
};

#endif //DIRTITEM_H
