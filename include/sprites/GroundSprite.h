#pragma once

#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"
#include "utils/Direction.h"

class GroundSprite : public GameSprite {
private:
    float gravity = 0.12f;
    float jumpSpeed = 0.0008f;
    float jumpVelocity = -0.43f;
    float velocityY = 0.0f;

    bool isOnGround = false;
    bool isJumping = false;

    bool isDamaging = false;
    Direction damagingDirection = Direction::NONE;
    float damageVelocity = 0.0f;
    float damageSpeed = 0.005;

    float hitboxPosX = 0;
    float hitboxSizeX = 0;
    float hitboxPosY = 0;
    float hitboxSizeY = 0;

protected:
    std::unordered_map<int, sf::IntRect> textures;
    int currentTexture = 0;
    int textureCounter = 0;
    Direction directionFacing = Direction::RIGHT;

    bool leftBlocked = false;
    bool rightBlocked = false;
    bool shouldAttemptJump = true;

    float health;

    void resetToStillTexture();

    void setHitboxPositionAndSize(float positionX, float sizeX, float positionY, float sizeY);

public:
    GroundSprite(const std::string& fileName, float movementSpeed, float health);

    virtual void update();

    void applyGravity();

    bool isSpriteOnGround() const;

    bool isSpriteJumping() const;
    void setSpriteJumping(bool jumping);

    void setSpriteOnGround(bool spriteOnGround);

    void jump();
    bool shouldJump() const;
    void setShouldJump(bool val);

    sf::FloatRect getHitbox() const;
    Direction getDirectionFacing() const;

    bool isLeftBlocked() const;
    bool isRightBlocked() const;

    void setLeftBlocked(bool leftBlocked);
    void setRightBlocked(bool rightBlocked);

    void animateWalking(Direction direction);

    float& getHealth();
    void damage(float damage, const Direction& direction);

};

#endif //GROUNDSPRITE_H
