#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/sprites/Steve.h"
#include "../../include/sprites/GroundSprite.h"
#include "../../include/sprites/utils/Direction.h"

using namespace std;

Steve::Steve(sf::Vector2f position) : GroundSprite("Steve.png", 0.08f) {
    textures[0] = sf::IntRect(
        {24, 48},
        {23, 23}
    );
    currentTexture = 0;
    sprite->setTextureRect(textures[0]);

    sprite->setPosition(position);
    sprite->setOrigin({ sprite->getLocalBounds().size.x - 11.5f, 0 });
    sprite->setScale(sf::Vector2f(5, 5));
    directionFacing = Direction::RIGHT;

    setHitboxPositionAndSize(30, 60, 50, 50);

    createTextures();
}

void Steve::handleEvent(sf::Event ev) {
    if (const auto* keyPressed = ev.getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Space) {
            jump();
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

void Steve::animateWalking(Direction direction) {
    if (currentTexture == 4) {
        currentTexture = 1;
    } else {
        currentTexture++;
    }

    if (textureCounter == 220) {
        sprite->setTextureRect(textures[currentTexture]);
        textureCounter = 0;
    } else {
        textureCounter++;
    }

    if (direction == Direction::RIGHT && !rightBlocked) {
        sprite->setScale(sf::Vector2f(5, 5));
        sprite->move(sf::Vector2f(movementSpeed, 0));
    } else if (direction == Direction::LEFT && !leftBlocked) {
        sprite->setScale(sf::Vector2f(-5, 5));
        sprite->move(sf::Vector2f(-movementSpeed, 0));
    }
}

void Steve::resetToStillTexture() {
    currentTexture = 0;
    sprite->setTextureRect(textures[currentTexture]);
}
