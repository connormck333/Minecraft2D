#pragma once

#ifndef CREEPER_H
#define CREEPER_H

#include "../AutomatedSprite.h"

class Creeper : public AutomatedSprite {
private:
    void createTextures();

public:
    explicit Creeper(Steve& steve, sf::Vector2f pos);
};

#endif //CREEPER_H
