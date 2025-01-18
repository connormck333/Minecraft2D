#pragma once

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>

#include "../blocks/Block.h"
#include "../sprites/Steve.h"
#include "../inventory/items/Item.h"

class EventHandler {
private:
    sf::RenderWindow& window;
    Steve& steve;
    std::vector<std::vector<Block*>>& world;

    std::string deleteBlockOnClick(const sf::Event& ev) const;

public:
    EventHandler(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>> &world);

    std::string handleEvents(const std::optional<sf::Event> &ev) const;

};

#endif //EVENTHANDLER_H
