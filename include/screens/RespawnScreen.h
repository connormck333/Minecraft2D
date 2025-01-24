#pragma once

#ifndef RESPAWNSCREEN_H
#define RESPAWNSCREEN_H

#include <SFML/Graphics.hpp>

class RespawnScreen {
private:
    sf::RenderWindow& window;

    sf::RectangleShape background;
    sf::Text* text;

public:
    RespawnScreen(sf::RenderWindow& window);

    void render();
};

#endif //RESPAWNSCREEN_H
