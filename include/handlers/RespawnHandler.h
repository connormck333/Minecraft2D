#pragma once

#ifndef RESPAWNHANDLER_H
#define RESPAWNHANDLER_H

#include "../sprites/Steve.h"
#include "../inventory/Hotbar.h"
#include "../GameState.h"
#include "../screens/RespawnScreen.h"

class RespawnHandler {
private:
    Steve& steve;
    Hotbar& hotbar;

    sf::Clock respawnClock;
    RespawnScreen* respawnScreen;

public:
    RespawnHandler(sf::RenderWindow& window, Steve& steve, Hotbar& hotbar);

    void checkForDeath(GameState& gameState);

    void respawn(const std::vector<std::vector<Block*>>& world, GameState& gameState);

    void render(const GameState& gameState);
};

#endif //RESPAWNHANDLER_H
