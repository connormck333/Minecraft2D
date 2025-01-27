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

public:
    explicit CraftItem(const std::string& fileName);

    void addRequirement(Item* requirement);

    void render(sf::RenderWindow& window, sf::Vector2f pos);
};

#endif //CRAFTITEM_H
