#pragma once

#ifndef WORLDGENERATOR_H
#define WORLDGENERATOR_H

#include "Tree.h"
#include "../sprites/Steve.h"

class WorldGenerator {
private:
    sf::RenderWindow& window;
    Steve& steve;
    std::vector<std::vector<Block*>>& world;

public:
    WorldGenerator(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world);

    void loadTrees() const;

    void updateWorld() const;
};

#endif //WORLDGENERATOR_H
