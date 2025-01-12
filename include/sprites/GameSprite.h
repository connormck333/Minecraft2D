#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

using namespace std;

class GameSprite {
protected:
    sf::Texture texture;
    optional<sf::Sprite> sprite;

    float movementSpeed;

public:
    GameSprite(const std::string& fileName, float movementSpeed);

    explicit GameSprite(const std::string& fileName);

    void loadTexture(const std::string& fileName);

    optional<sf::Sprite> getSprite();

    bool isStatic() const;
};

#endif