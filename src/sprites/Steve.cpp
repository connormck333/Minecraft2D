#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/sprites/Steve.h"
#include "../../include/sprites/GameSprite.h"

using namespace std;


Steve::Steve() : GameSprite("Steve.png", 5.0f) {
    textures[0] = sf::IntRect(
        {24, 48},
        {23, 23}
    );
    currentTexture = 0;
    sprite->setTextureRect(textures[0]);

    sprite->setPosition(sf::Vector2f(353, 229));
    sprite->setScale(sf::Vector2f(5, 5));

    createTextures();
}

void Steve::moveSprite() {
    if (isKeyPressed(sf::Keyboard::Key::W)) {
        sprite->move(sf::Vector2f(0, -(movementSpeed)));
        animateWalking();
    } else if (isKeyPressed(sf::Keyboard::Key::S)) {
        sprite->move(sf::Vector2f(0, movementSpeed));
        animateWalking();
    } else if (isKeyPressed(sf::Keyboard::Key::A)) {
        sprite->move(sf::Vector2f(-(movementSpeed), 0));
        animateWalking();
    } else if (isKeyPressed(sf::Keyboard::Key::D)) {
        sprite->move(sf::Vector2f(movementSpeed, 0));
        animateWalking();
    } else {
        resetToStillTexture();
    }
}

void Steve::createTextures() {
    textures[1] = sf::IntRect(
        {24, 96},
        {23, 23}
    );
    textures[2] = sf::IntRect(
        {48, 96},
        {23, 23}
    );
    textures[3] = sf::IntRect(
        {72, 96},
        {23, 23}
    );
    textures[4] = sf::IntRect(
        {96, 96},
        {23, 23}
    );
}

void Steve::animateWalking() {
    if (currentTexture == 4) {
        currentTexture = 1;
    } else {
        currentTexture++;
    }

    sprite->setTextureRect(textures[currentTexture]);
}

void Steve::resetToStillTexture() {
    currentTexture = 0;
    sprite->setTextureRect(textures[currentTexture]);
}
