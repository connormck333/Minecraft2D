#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../GroundSprite.h"

class Zombie : public GroundSprite {
private:
    void createTextures();

public:
    explicit Zombie(sf::Vector2f pos);
};

#endif //ZOMBIE_H
