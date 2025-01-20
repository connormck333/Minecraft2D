#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H

#include "../sprites/GameSprite.h"
#include "./items/Item.h"

class Hotbar : public GameSprite {
private:
    sf::RenderWindow& window;
    std::vector<Item*> slots;

    sf::RectangleShape selectedSquare;
    int selectedSlot = 0;

    void loadSelectedSlot();
    void addNewItem(const std::string& itemId);
    void updatePosition();
    void updateSlots() const;
    void updateSelectedSlot();

public:
    Hotbar(sf::RenderWindow& window);

    void update(const std::string &itemId);

    void draw() const;

    void setSelectedSlot(int slotId);
    Item* getSelectedItem() const;
};

#endif //HOTBAR_H
