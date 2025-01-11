#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/sprites/Steve.h"
#include "../../include/sprites/GameSprite.h"

using namespace std;


Steve::Steve() : GameSprite("Steve.png", 5.0f) {
    this->sprite->setTextureRect(sf::IntRect(
        {24, 48},
        {23, 23})
        );

    sprite->setPosition(sf::Vector2f(353, 229));
    sprite->setScale(sf::Vector2f(5, 5));
}

void Steve::moveSprite() {
    if (isKeyPressed(sf::Keyboard::Key::W)) {
        sprite->move(sf::Vector2f(0, -(movementSpeed)));
    } else if (isKeyPressed(sf::Keyboard::Key::S)) {
        sprite->move(sf::Vector2f(0, movementSpeed));
    } else if (isKeyPressed(sf::Keyboard::Key::A)) {
        sprite->move(sf::Vector2f(-(movementSpeed), 0));
    } else if (isKeyPressed(sf::Keyboard::Key::D)) {
        sprite->move(sf::Vector2f(movementSpeed, 0));
    }
}