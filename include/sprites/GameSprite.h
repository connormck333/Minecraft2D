#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

using namespace std;

class GameSprite {
protected:
    optional<sf::Sprite> sprite;

    float movementSpeed;

public:
    // Constructor
    explicit GameSprite(const std::string& fileName, float movementSpeed);

    optional<sf::Sprite> getSprite();
};

#endif