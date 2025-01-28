#pragma once

#ifndef CRAFTITEM_H
#define CRAFTITEM_H

#include <SFML/Graphics.hpp>
#include "../../sprites/GameSprite.h"
#include "../items/Item.h"

class CraftItem : public Item {
private:
    sf::RectangleShape craftBox;
    std::vector<Item*> craftRequirements;
    sf::Clock craftClock;

public:
    explicit CraftItem(const std::string& id, const std::string& fileName);

    void addRequirement(Item* requirement);
    [[nodiscard]] std::vector<Item*>& getRequirements();

    [[nodiscard]] sf::Vector2f getBoxPos() const;
    [[nodiscard]] sf::Vector2f getBoxSize() const;

    void setBoxGreen();
    void setBoxRed();
    void resetBoxColor();

    virtual Item* getHotbarItem();

    void render(sf::RenderWindow& window, sf::Vector2f pos);
};

#endif //CRAFTITEM_H
