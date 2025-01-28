#include "../../include/terrain/Tree.h"

#include "../../include/Constants.h"
#include "../../include/blocks/Leaves.h"
#include "../../include/blocks/OakWood.h"

Tree::Tree(std::vector<std::vector<Block*>>& world, sf::Vector2f rootPos) : world(world) {
    rootX = rootPos.x;
    rootY = rootPos.y + 1;

    loadTree();
}

void Tree::loadTree() const {
    for (int i = 0; i < 3; i++) {
        int y = rootY + i;
        world[y][rootX] = new OakWood(sf::Vector2f(rootX * Constants::BLOCK_SIZE, (Constants::WORLD_HEIGHT - y) * Constants::BLOCK_SIZE));
    }

    std::vector<sf::Vector2f> leavesPositions = getLeavesPositions();

    for (sf::Vector2f pos : leavesPositions) {
        int x = pos.x;
        int y = pos.y;
        pos.x = pos.x * Constants::BLOCK_SIZE;
        pos.y = (Constants::WORLD_HEIGHT - pos.y) * Constants::BLOCK_SIZE;

        world[y][x] = new Leaves(pos);
    }
}

std::vector<sf::Vector2f> Tree::getLeavesPositions() const {
    std::vector<sf::Vector2f> leavesPositions;
    leavesPositions.push_back(sf::Vector2f(rootX, rootY + 3));
    leavesPositions.push_back(sf::Vector2f(rootX, rootY + 4));
    leavesPositions.push_back(sf::Vector2f(rootX, rootY + 5));

    leavesPositions.push_back(sf::Vector2f(rootX + 1, rootY + 3));
    leavesPositions.push_back(sf::Vector2f(rootX + 1, rootY + 4));

    leavesPositions.push_back(sf::Vector2f(rootX - 1, rootY + 3));
    leavesPositions.push_back(sf::Vector2f(rootX - 1, rootY + 4));

    return leavesPositions;
}
