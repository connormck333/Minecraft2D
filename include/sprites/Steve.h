#ifndef STEVE_H
#pragma once

#define STEVE_H

#include "GroundSprite.h"
#include "utils/Direction.h"

class Steve : public GroundSprite {
private:
    void createTextures();

public:
    explicit Steve(sf::Vector2f pos);

    void handleEvent(sf::Event ev);

    void respawn(sf::Vector2f spawnPos);
};

#endif //STEVE_H
