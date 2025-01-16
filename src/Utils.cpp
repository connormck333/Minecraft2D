#include "../include/Utils.h"

#include <vector>
#include <random>
#include <SFML/System/Vector2.hpp>

#include "../include/Constants.h"
#include "../include/blocks/Block.h"
#include "../include/blocks/DiamondOre.h"
#include "../include/blocks/EmeraldOre.h"
#include "../include/blocks/GoldOre.h"
#include "../include/blocks/IronOre.h"

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

Block* getRandomOre(const sf::Vector2f pos) {
    int randomNumber = getRandomInt(0, 3);

    switch (randomNumber) {
        case 0: return new IronOre(pos);
        case 1: return new GoldOre(pos);
        case 2: return new DiamondOre(pos);
        default: return new EmeraldOre(pos);
    }
}

int getRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distribution(min, max);

    int num = distribution(gen);
    cout << num << endl;
    return num;
}

bool getRandomBool(int chance) {
    return getRandomInt(0, chance) == 0;
}