#pragma once

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SFML/Graphics.hpp>

#include "SpriteHandler.h"
#include "../blocks/Block.h"
#include "../sprites/Steve.h"
#include "../inventory/Hotbar.h"
#include "../screens/CraftScreen.h"

class EventHandler {
private:
    sf::RenderWindow& window;
    std::vector<std::vector<Block*>>& world;
    Steve& steve;
    Hotbar& hotbar;
    SpriteHandler& spriteHandler;
    CraftScreen& craftScreen;

    sf::Vector2f getMousePos(const sf::Event::MouseButtonPressed* mouse) const;

    void deleteBlockOnClick(const sf::Event& ev) const;
    void placeBlockOnRightClick(const sf::Event& ev) const;

    [[nodiscard]] bool canBreakMaterial(const Block* block) const;
    [[nodiscard]] bool canBreakBlock(int x, int y, int steveX, int steveY) const;
    [[nodiscard]] bool canPlaceBlock(int x, int y) const;
    [[nodiscard]] bool isWithinReach(int x, int y, int steveX, int steveY) const;
    [[nodiscard]] bool isSpriteWithinReach(sf::Vector2f& stevePos, sf::Vector2f& spritePos) const;

    void damageSpriteOnClick(const sf::Event& ev) const;

    void craftItemOnClick(const sf::Event& ev) const;

public:
    EventHandler(
        sf::RenderWindow& window,
        std::vector<std::vector<Block*>> &world,
        Steve& steve, Hotbar& hotbar,
        SpriteHandler& spriteHandler,
        CraftScreen& craftScreen
    );

    void handleEvents(const std::optional<sf::Event> &ev, bool isInventoryOpen) const;
};

#endif //EVENTHANDLER_H
