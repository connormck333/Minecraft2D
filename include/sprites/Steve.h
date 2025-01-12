#ifndef STEVE_H
#define STEVE_H

#include "GroundSprite.h"
#include "utils/Direction.h"

class Steve : public GroundSprite {
private:
    std::unordered_map<int, sf::IntRect> textures;
    int currentTexture;
    Direction directionFacing;

    void createTextures();
    void animateWalking(Direction direction);
    void resetToStillTexture();

public:
    Steve();

    void moveSprite(sf::Event ev);

    void changeDirection();
};

#endif //STEVE_H
