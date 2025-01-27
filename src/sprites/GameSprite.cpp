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
    if (!fileName.empty() && texture.loadFromFile("assets/sprites/" + fileName)) {
        sprite.emplace(texture);
    }
}

void GameSprite::loadRect(int x, int y, int height, int width) {
    const sf::IntRect blockRect(
        {x, y},
        {width, height}
    );
    sprite->setTextureRect(blockRect);
}

optional<sf::Sprite>& GameSprite::getSprite() {
    return sprite;
}

bool GameSprite::isStatic() const {
    return movementSpeed != 0.0f;
}
