#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "../../include/sprites/GameSprite.h"

using namespace std;
namespace fs = std::filesystem;

GameSprite::GameSprite(const std::string& fileName, float movementSpeed)
    : movementSpeed(movementSpeed) {

    sf::Texture texture;
    if (texture.loadFromFile("assets/sprites/" + fileName)) {
        sprite.emplace(texture);
    } else {
        std::cout << "Failed to load sprite file: " << fileName << std::endl;
    }
}

optional<sf::Sprite> GameSprite::getSprite() {
    return sprite;
}