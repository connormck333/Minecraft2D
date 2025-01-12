#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"

class GroundSprite : public GameSprite {
private:
    float fallSpeed;
    bool isOnGround = false;
public:
    GroundSprite(const string& fileName, float movementSpeed, float fallSpeed);

    void applyGravity();

    bool isSpriteOnGround();

    void setSpriteOnGround(bool spriteOnGround);
};

#endif //GROUNDSPRITE_H
