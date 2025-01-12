#include "../../include/sprites/GroundSprite.h"

GroundSprite::GroundSprite(const std::string& fileName, const float movementSpeed, const float fallSpeed)
: GameSprite(fileName, movementSpeed), fallSpeed(fallSpeed) {}

void GroundSprite::applyGravity() {
    sprite->move(sf::Vector2f(0, fallSpeed));
}

bool GroundSprite::isSpriteOnGround() const {
    return isOnGround;
}

void GroundSprite::setSpriteOnGround(bool spriteOnGround) {
    isOnGround = spriteOnGround;
}


