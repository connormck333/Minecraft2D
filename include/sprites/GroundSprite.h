#pragma once

#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"

class GroundSprite : public GameSprite {
private:
    float gravity = 0.02f;
    float jumpSpeed = 0.02f;
    float jumpVelocity = -1.8f;
    float velocityY = 0.0f;
    bool isOnGround = false;
    bool isJumping = false;

    float hitboxPos = 0;
    float hitboxSize = 0;

protected:
    void setHitboxPositionAndSize(float position, float size);

public:
    GroundSprite(const std::string& fileName, float movementSpeed);

    void update();

    void applyGravity();

    bool isSpriteOnGround() const;

    bool isSpriteJumping() const;

    void setSpriteOnGround(bool spriteOnGround);

    void jump();

    sf::FloatRect getHitbox() const;
};

#endif //GROUNDSPRITE_H
