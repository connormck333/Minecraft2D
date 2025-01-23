#pragma once

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "../sprites/GameSprite.h"

class Healthbar {
private:
    sf::RenderWindow& window;
    int health;
    std::vector<GameSprite*> hearts;

public:
    Healthbar(sf::RenderWindow& window);

    void update() const;
};

#endif //HEALTHBAR_H
