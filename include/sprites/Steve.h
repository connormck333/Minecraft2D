#ifndef STEVE_H
#define STEVE_H

#include "GroundSprite.h"

class Steve : public GroundSprite {
private:
    unordered_map<int, sf::IntRect> textures;
    int currentTexture;

    void createTextures();
    void animateWalking();
    void resetToStillTexture();

public:
    Steve();

    void moveSprite(sf::Event ev);

    void update();
};

#endif //STEVE_H
