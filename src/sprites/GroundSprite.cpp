#include "../../include/sprites/GroundSprite.h"
#include "../../include/Utils.h"

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

void GroundSprite::setSpriteJumping(bool jumping) {
    isJumping = jumping;
}

void GroundSprite::setSpriteOnGround(bool spriteOnGround) {
    isOnGround = spriteOnGround;
}

void GroundSprite::jump() {
    if (!isJumping && isOnGround) {
        isJumping = true;
    }
}

bool GroundSprite::shouldJump() const {
    return shouldAttemptJump;
}

void GroundSprite::setShouldJump(const bool val) {
    shouldAttemptJump = val;
}

void GroundSprite::setHitboxPositionAndSize(const float positionX, const float sizeX, const float positionY, const float sizeY) {
    hitboxPosX = positionX;
    hitboxSizeX = sizeX;
    hitboxPosY = positionY;
    hitboxSizeY = sizeY;
}

sf::FloatRect GroundSprite::getHitbox() const {
    sf::FloatRect hitbox = sprite->getGlobalBounds();
    hitbox.position.x += hitboxPosX;
    hitbox.size.x -= hitboxSizeX;
    hitbox.position.y += hitboxPosY;
    hitbox.size.y -= hitboxSizeY;

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

void GroundSprite::resetToStillTexture() {
    currentTexture = 0;
    sprite->setTextureRect(textures[currentTexture]);
}

void GroundSprite::animateWalking(Direction direction) {
    if (currentTexture == textures.size() - 1) {
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