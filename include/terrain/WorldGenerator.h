#pragma once

#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include "../sprites/Steve.h"

class Block;

class WorldGenerator {
private:
    sf::RenderWindow& window;
    Steve& steve;
    std::vector<std::vector<Block*>>& world;

public:
    WorldGenerator(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world);

    void updateWorld();
};

#endif //WORLDGENERATOR_H
