#pragma once

#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>

class Screen {
protected:
    sf::RenderWindow& window;
    sf::RectangleShape background;

public:
    explicit Screen(sf::RenderWindow& window);
    virtual ~Screen() = default;

    virtual void render();
};

#endif //SCREEN_H
