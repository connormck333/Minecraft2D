#ifndef STEVE_H
#pragma once

#define STEVE_H

#include "GroundSprite.h"
#include "utils/Direction.h"

class Steve : public GroundSprite {
private:
    void createTextures();

public:
    Steve(sf::Vector2f pos);

    void handleEvent(sf::Event ev);
};

#endif //STEVE_H
