#include <vector>
#include <SFML/System/Vector2.hpp>

#include "../include/Constants.h"
#include "../include/blocks/Block.h"

class Block;
using namespace std;

sf::Vector2f getSteveSpawnPos(const vector<vector<Block*>>& world) {
    int stevePosY = -1;
    int stevePosX = Constants::WORLD_WIDTH / 2;
    for (int i = Constants::WORLD_HEIGHT - 1; i >= 0; i--) {
        if (world[i][stevePosX]->getSprite().has_value()) {
            stevePosY = i;
            break;
        }
    }

    sf::Vector2f stevePos = world[stevePosY][stevePosX]->getSprite().value().getPosition();
    stevePos.y -= Constants::BLOCK_SIZE * 2;
    stevePos.x += Constants::BLOCK_SIZE / 2;

    return stevePos;
}