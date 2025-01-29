#pragma once

#ifndef RESPAWNHANDLER_H
#define RESPAWNHANDLER_H

#include "../sprites/Steve.h"
#include "../inventory/Hotbar.h"
#include "../GameState.h"
#include "../screens/RespawnScreen.h"

class RespawnHandler final {
private:
    sf::RenderWindow& window;
    Steve& steve;
    Hotbar& hotbar;

    sf::Clock timeAliveClock;
    sf::Clock respawnTimer;
    RespawnScreen* respawnScreen;
    sf::Text* currentTimeText;

public:
    RespawnHandler(sf::RenderWindow& window, Steve& steve, Hotbar& hotbar);

    void checkForDeath(GameState& gameState);

    void respawn(const std::vector<std::vector<Block*>>& world, GameState& gameState) const;

    void render(const GameState& gameState) const;

    [[nodiscard]] int getTimeAliveSeconds() const;
    void stopTimeAliveClock();
};

#endif //RESPAWNHANDLER_H
