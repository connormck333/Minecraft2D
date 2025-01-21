#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../AutomatedSprite.h"

class Zombie : public AutomatedSprite {
private:
    void createTextures();

public:
    explicit Zombie(Steve& steve, sf::Vector2f pos);
};

#endif //ZOMBIE_H
