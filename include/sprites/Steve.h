#ifndef STEVE_H
#define STEVE_H

#include "GameSprite.h"

class Steve: public GameSprite {
private:
    unordered_map<int, sf::IntRect> textures;
    int currentTexture;

    void createTextures();
    void animateWalking();
    void resetToStillTexture();

public:
    Steve();

    void moveSprite();
};

#endif //STEVE_H
