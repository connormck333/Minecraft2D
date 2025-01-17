#pragma once

#ifndef TREE_H
#define TREE_H

#include <SFML/Graphics.hpp>
#include "../blocks/Block.h"

class Tree {
private:
    std::vector<std::vector<Block*>>& world;
    int rootX;
    int rootY;

    std::vector<sf::Vector2f> getLeavesPositions() const;

    void loadTree() const;

public:
    Tree(std::vector<std::vector<Block*>>& world, sf::Vector2f rootPos);
};

#endif //TREE_H
