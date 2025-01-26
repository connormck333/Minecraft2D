#pragma once

#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "../sprites/Steve.h"
#include "../blocks/Block.h"

class SpriteHandler {
private:
    sf::RenderWindow& window;
    std::vector<std::vector<Block*>>& world;
    Steve& steve;

    sf::Clock spriteClock;
    std::vector<GameSprite*> sprites;

    [[nodiscard]] sf::Vector2f createSpritePos() const;
    void createNewSprite();

public:
    SpriteHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>>& world, Steve& steve);

    void addSprite(GameSprite* sprite);
    void removeSprite(GameSprite* sprite);

    [[nodiscard]] Steve& getSteve() const;
    [[nodiscard]] std::vector<GameSprite*> getSprites(bool includeSteve) const;

    void update();
    void draw() const;
};

#endif //SPRITEHANDLER_H
