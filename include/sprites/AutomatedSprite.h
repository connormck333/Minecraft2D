#pragma once

#ifndef AUTOMATEDSPRITE_H
#define AUTOMATEDSPRITE_H

#include "./GroundSprite.h"
#include "Steve.h"

class AutomatedSprite : public GroundSprite {
private:
    sf::Clock damageClock;
    int damageCooldown;

protected:
    Steve& steve;

    Direction getDirectionOfSteve() const;

    void shouldJump();

public:
    AutomatedSprite(Steve& steve, const std::string& fileName, float movementSpeed);

    void update() override;
};

#endif //AUTOMATEDSPRITE_H
