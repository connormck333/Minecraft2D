#pragma once

#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include "Tree.h"
#include "../handlers/SpriteHandler.h"
#include "../sprites/Steve.h"

class WorldGenerator {
private:
    sf::RenderWindow& window;
    SpriteHandler& spriteHandler;
    std::vector<std::vector<Block*>>& world;

    std::vector<GroundSprite*> getGroundSprites(std::vector<GameSprite*>& sprites, int minX, int minY, int maxX, int maxY) const;

    bool decideShouldJumpForAutomatedSprites(GroundSprite& sprite) const;

public:
    WorldGenerator(sf::RenderWindow& window, SpriteHandler& spriteHandler, std::vector<std::vector<Block*>>& world);

    void loadTrees() const;

    void updateWorld() const;
};

#endif //WORLDGENERATOR_H
