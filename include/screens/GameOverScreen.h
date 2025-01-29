#pragma once

#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "../handlers/RespawnHandler.h"

class GameOverScreen final : public Screen {
private:
    RespawnHandler& respawnHandler;
    sf::Text* winningMessage;

public:
    GameOverScreen(sf::RenderWindow& window, RespawnHandler& respawnHandler);

    void render() override;
};

#endif //GAMEOVERSCREEN_H
