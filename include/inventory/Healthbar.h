#pragma once

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "../sprites/GameSprite.h"

class Healthbar {
private:
    sf::RenderWindow& window;
    std::vector<GameSprite*> hearts;
    float& health;

public:
    Healthbar(sf::RenderWindow& window, float& health);

    void update() const;
};

#endif //HEALTHBAR_H
