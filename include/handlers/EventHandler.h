#pragma once

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>

#include "../blocks/Block.h"
#include "../sprites/Steve.h"
#include "../inventory/Hotbar.h"

class EventHandler {
private:
    sf::RenderWindow& window;
    std::vector<std::vector<Block*>>& world;
    Steve& steve;
    Hotbar& hotbar;

    sf::Vector2f getMousePos(const sf::Event::MouseButtonPressed* mouse) const;

    void deleteBlockOnClick(const sf::Event& ev) const;
    void placeBlockOnRightClick(const sf::Event& ev) const;

    bool canBreakOrPlaceBlock(int x, int y, int steveX, int steveY) const;
    bool isWithinDistance(int x, int y, int steveX, int steveY) const;

public:
    EventHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>> &world, Steve& steve, Hotbar& hotbar);

    void handleEvents(const std::optional<sf::Event> &ev) const;

};

#endif //EVENTHANDLER_H
