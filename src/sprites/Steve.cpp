#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/sprites/Steve.h"
#include "../../include/sprites/GroundSprite.h"

using namespace std;


Steve::Steve() : GroundSprite("Steve.png", 5.0f, 0.02f) {
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

void Steve::update() {
    applyGravity();
}

void Steve::moveSprite(sf::Event ev) {
    if (const auto* keyPressed = ev.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
            sprite->move(sf::Vector2f(-(movementSpeed), 0));
            animateWalking();
        } else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
            sprite->move(sf::Vector2f(movementSpeed, 0));
            animateWalking();
        }
    } else if (const auto* keyReleased = ev.getIf<sf::Event::KeyReleased>()) {
        if (
            keyReleased->scancode == sf::Keyboard::Scancode::A ||
            keyReleased->scancode == sf::Keyboard::Scancode::D
        ) {
            resetToStillTexture();
        }
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
