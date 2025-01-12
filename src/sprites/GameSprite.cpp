#include <iostream>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include "../../include/sprites/GameSprite.h"

using namespace std;
namespace fs = filesystem;

GameSprite::GameSprite(const string& fileName, float movementSpeed)
    : movementSpeed(movementSpeed) {

    loadTexture(fileName);
}

GameSprite::GameSprite(const string &fileName) {
    loadTexture(fileName);
    movementSpeed = 0.0f;
}

void GameSprite::loadTexture(const std::string &fileName) {
    if (texture.loadFromFile("assets/sprites/" + fileName)) {
        sprite.emplace(texture);
    } else {
        cout << "Failed to load sprite file: " << fileName << endl;
    }
}

optional<sf::Sprite> GameSprite::getSprite() {
    return sprite;
}

bool GameSprite::isStatic() const {
    return movementSpeed != 0.0f;
}
