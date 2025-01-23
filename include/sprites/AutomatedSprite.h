#pragma once

#ifndef AUTOMATEDSPRITE_H
#define AUTOMATEDSPRITE_H

#include "./GroundSprite.h"
#include "Steve.h"

class AutomatedSprite : public GroundSprite {
private:
    Steve& steve;
    int damageCooldown;
    int currentDamageTick;

    Direction getDirectionOfSteve() const;

public:
    AutomatedSprite(Steve& steve, const std::string& fileName, float movementSpeed);

    void update() override;
};

#endif //AUTOMATEDSPRITE_H
