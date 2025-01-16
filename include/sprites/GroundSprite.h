#pragma once

#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"
#include "utils/Direction.h"

class GroundSprite : public GameSprite {
private:
    float gravity = 0.12f;
    float jumpSpeed = 0.0075f;
    float jumpVelocity = -1.1f;
    float velocityY = 0.0f;

    bool isOnGround = false;
    bool isJumping = false;

    float hitboxPosX = 0;
    float hitboxSizeX = 0;
    float hitboxPosY = 0;
    float hitboxSizeY = 0;

protected:
    bool leftBlocked = false;
    bool rightBlocked = false;

    void setHitboxPositionAndSize(float positionX, float sizeX, float positionY, float sizeY);

public:
    GroundSprite(const std::string& fileName, float movementSpeed);

    void update();

    void applyGravity();

    bool isSpriteOnGround() const;

    bool isSpriteJumping() const;
    void setSpriteJumping(bool jumping);

    void setSpriteOnGround(bool spriteOnGround);

    void jump();

    sf::FloatRect getHitbox() const;

    bool isLeftBlocked() const;
    bool isRightBlocked() const;

    void setLeftBlocked(bool leftBlocked);
    void setRightBlocked(bool rightBlocked);
};

#endif //GROUNDSPRITE_H
