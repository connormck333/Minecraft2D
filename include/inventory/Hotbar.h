#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H

#include "../sprites/GameSprite.h"
#include "./items/Item.h"
#include "crafting/CraftItem.h"

class Hotbar final : public GameSprite {
private:
    sf::RenderWindow& window;
    std::vector<Item*> slots;

    sf::RectangleShape selectedSquare;
    int selectedSlot = 0;

    void loadSelectedSlot();
    void updatePosition();
    void updateSlots();
    void updateSelectedSlot();
    void deleteSlot(int slotId);

public:
    Hotbar(sf::RenderWindow& window);

    void addNewItem(Item* item);
    [[nodiscard]] bool addNewItem(CraftItem* item);

    void update();
    void draw() const;

    void setSelectedSlot(int slotId);
    Item* getSelectedItem() const;
};

#endif //HOTBAR_H
