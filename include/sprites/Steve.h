#ifndef STEVE_H
#pragma once

#define STEVE_H

#include "GroundSprite.h"
#include "utils/Direction.h"

class Steve : public GroundSprite {
private:
    std::unordered_map<int, sf::IntRect> textures;
    int currentTexture;
    int textureCounter;
    Direction directionFacing;

    void createTextures();
    void resetToStillTexture();

public:
    Steve();

    void handleEvent(sf::Event ev);
    void animateWalking(Direction direction);

    void changeDirection();
};

#endif //STEVE_H
