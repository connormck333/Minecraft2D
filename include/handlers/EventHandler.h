#pragma once

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>

#include "../blocks/Block.h"
#include "../sprites/Steve.h"

class EventHandler {
private:
    sf::RenderWindow& window;
    Steve& steve;
    std::vector<std::vector<Block*>>& world;

    void deleteBlockOnClick(const sf::Event& ev) const;

public:
    EventHandler(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>> &world);

    void handleEvents(const std::optional<sf::Event> &ev) const;

};

#endif //EVENTHANDLER_H
