#pragma once

#ifndef CREEPER_H
#define CREEPER_H

#include "../AutomatedSprite.h"
#include "../../blocks/Block.h"
#include "../../handlers/SpriteHandler.h"

class Creeper : public AutomatedSprite {
private:
    std::vector<std::vector<Block*>>& world;
    SpriteHandler& spriteHandler;

    sf::Clock explodingClock;
    std::unordered_map<int, sf::IntRect> explodingTextures;
    bool exploding = false;

    void createTextures();

    void explode();
    void destroyWorld();

public:
    explicit Creeper(std::vector<std::vector<Block*>>& world, SpriteHandler& spriteHandler, Steve& steve, sf::Vector2f pos);

    void update() override;
};

#endif //CREEPER_H
