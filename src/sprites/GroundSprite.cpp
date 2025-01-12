#include "../../include/sprites/GroundSprite.h"

GroundSprite::GroundSprite(const std::string& fileName, const float movementSpeed)
: GameSprite(fileName, movementSpeed) {}

void GroundSprite::update() {
    if (isJumping) {
        velocityY += jumpSpeed;
        sprite->move(sf::Vector2f(0, velocityY));

        if (isOnGround) {
            velocityY = 0;
            isJumping = false;
        }
    } else {
        applyGravity();
    }
}

void GroundSprite::applyGravity() {
    if (!isOnGround) {
        sprite->move(sf::Vector2f(0, gravity));
    }
}

bool GroundSprite::isSpriteOnGround() const {
    return isOnGround;
}

void GroundSprite::setSpriteOnGround(bool spriteOnGround) {
    isOnGround = spriteOnGround;
}

void GroundSprite::jump() {
    if (!isJumping && isOnGround) {
        isJumping = true;
        velocityY = jumpVelocity;
    }
}

