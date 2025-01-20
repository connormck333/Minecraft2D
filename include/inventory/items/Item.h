#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "../../sprites/GameSprite.h"

class Block;

class Item : public GameSprite {
private:
    std::string id;
    int quantity;
    bool isBlock = true;

    std::optional<sf::Text> quantityText;

    sf::Vector2i getSlotPosition(int slotId) const;

public:
    Item(std::string id, const std::string& fileName);
    Item(std::string id, const std::string& fileName, bool isBlock);

    std::string getId() const;
    std::optional<sf::Text> getQuantityText() const;

    void setSlotPosition(const sf::RenderWindow& window, int slotId);

    void incrementQuantity();
    void decrementQuantity();
    int getQuantity() const;

    virtual bool canBePlaced() const;
    virtual Block* createBlock(const sf::Vector2f& pos);
};

#endif //ITEM_H
