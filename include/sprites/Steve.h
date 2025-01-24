#ifndef STEVE_H
#pragma once

#define STEVE_H

#include "GroundSprite.h"
#include "utils/Direction.h"

class Steve : public GroundSprite {
private:
    int health;
    void createTextures();

public:
    Steve(sf::Vector2f pos);

    void handleEvent(sf::Event ev);

    int& getHealth();
    void damage(int damage);
    void respawn(sf::Vector2f spawnPos);
};

#endif //STEVE_H
