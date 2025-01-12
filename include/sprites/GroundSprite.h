#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"

class GroundSprite : public GameSprite {
private:
    float gravity = 0.02f;
    float jumpSpeed = 0.2f;
    float jumpVelocity = -50.0f;
    float velocityY = 0.0f;
    bool isOnGround = false;
    bool isJumping = false;
public:
    GroundSprite(const std::string& fileName, float movementSpeed);

    void update();

    void applyGravity();

    bool isSpriteOnGround() const;

    void setSpriteOnGround(bool spriteOnGround);

    void jump();
};

#endif //GROUNDSPRITE_H
