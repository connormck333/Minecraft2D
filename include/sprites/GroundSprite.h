#ifndef GROUNDSPRITE_H
#define GROUNDSPRITE_H

#include "GameSprite.h"

class GroundSprite : public GameSprite {
private:
    float fallSpeed;
public:
    GroundSprite(const string& fileName, float movementSpeed, float fallSpeed);

    void applyGravity();
};

#endif //GROUNDSPRITE_H
