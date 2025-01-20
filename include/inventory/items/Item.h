#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "../../sprites/GameSprite.h"

class Block;

class Item : public GameSprite {
private:
    std::string id;
    int slotId;
    int quantity;

    std::optional<sf::Text> quantityText;

    sf::Vector2i getSlotPosition() const;

public:
    Item(std::string id, int slotId, const std::string& fileName);

    std::string getId() const;
    std::optional<sf::Text> getQuantityText() const;

    void setSlotPosition(const sf::RenderWindow& window);

    void incrementQuantity();
    void decrementQuantity();

    virtual Block* createBlock(const sf::Vector2f& pos);
};

#endif //ITEM_H
