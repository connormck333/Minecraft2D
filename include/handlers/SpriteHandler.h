#pragma once

#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "../sprites/Steve.h"
#include "../blocks/Block.h"

class SpriteHandler {
private:
    sf::RenderWindow& window;
    Steve& steve;
    std::vector<GameSprite*> sprites;

public:
    SpriteHandler(sf::RenderWindow& window, Steve& steve);

    void addSprite(GameSprite* sprite);

    Steve& getSteve() const;
    std::vector<GameSprite*> getSprites() const;

    void update() const;
    void draw() const;
};

#endif //SPRITEHANDLER_H
