#include "../../include/sprites/GroundSprite.h"

GroundSprite::GroundSprite(const std::string& fileName, const float movementSpeed)
: GameSprite(fileName, movementSpeed) {}

void GroundSprite::update() {
    if (isJumping) {
        velocityY -= jumpSpeed;
        sprite->move(sf::Vector2f(0, velocityY));

        if (velocityY <= jumpVelocity) {
            velocityY = 0;
            isJumping = false;
        }
    } else {
        applyGravity();
    }
}

void GroundSprite::applyGravity() {
    if (!isOnGround && !isJumping) {
        sprite->move(sf::Vector2f(0, gravity));
    }
}

bool GroundSprite::isSpriteOnGround() const {
    return isOnGround;
}

bool GroundSprite::isSpriteJumping() const {
    return isJumping;
}

void GroundSprite::setSpriteOnGround(bool spriteOnGround) {
    isOnGround = spriteOnGround;
}

void GroundSprite::jump() {
    if (!isJumping && isOnGround) {
        // setSpriteOnGround(false);
        isJumping = true;
        // velocityY = jumpVelocity;
    }
}

void GroundSprite::setHitboxPositionAndSize(const float position, const float size) {
    hitboxPos = position;
    hitboxSize = size;
}

sf::FloatRect GroundSprite::getHitbox() const {
    sf::FloatRect hitbox = sprite->getGlobalBounds();
    hitbox.position.x += hitboxPos;
    hitbox.size.x -= hitboxSize;

    return hitbox;
}

bool GroundSprite::isLeftBlocked() const {
    return leftBlocked;
}

bool GroundSprite::isRightBlocked() const {
    return rightBlocked;
}

void GroundSprite::setLeftBlocked(bool leftBlocked) {
    this->leftBlocked = leftBlocked;
}

void GroundSprite::setRightBlocked(bool rightBlocked) {
    this->rightBlocked = rightBlocked;
}
