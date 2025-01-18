#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "../../sprites/GameSprite.h"

class Item : public GameSprite {
private:
    std::string id;
    int slotId;
    int quantity;

    sf::Vector2i getSlotPosition();

public:
    Item(std::string id, int slotId, const std::string& fileName);

    std::string getId() const;

    void setSlotPosition(const sf::RenderWindow& window);

    void incrementQuantity();
    void decrementQuantity();
};

#endif //ITEM_H
