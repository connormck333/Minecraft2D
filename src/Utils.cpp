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
#include "../include/inventory/items/DiamondItem.h"
#include "../include/inventory/items/DirtItem.h"
#include "../include/inventory/items/StoneItem.h"
#include "../include/inventory/items/WoodItem.h"


sf::Vector2f getSteveSpawnPos(const std::vector<std::vector<Block*>>& world) {
    int stevePosX = Constants::WORLD_WIDTH / 2;
    int stevePosY = findTopYLevelAtX(world, stevePosX);

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

    return distribution(gen);
}

bool getRandomBool(int chance) {
    return getRandomInt(0, chance) == 0;
}

int findTopYLevelAtX(const std::vector<std::vector<Block*>>& world, const int x) {
    for (int i = Constants::WORLD_HEIGHT - 1; i >= 0; i--) {
        if (world[i][x]->getSprite().has_value()) {
            return i;
        }
    }

    return -1;
}

sf::Vector2f getRelativeBlockPos(float x, float y) {
    sf::Vector2f pos;
    pos.y = static_cast<int>(Constants::WORLD_HEIGHT - (y / Constants::BLOCK_SIZE) + 1);
    pos.x = static_cast<int>(x / Constants::BLOCK_SIZE);

    return pos;
}

sf::Vector2f getRelativeBlockPos(const sf::Vector2f pos) {
    return getRelativeBlockPos(pos.x, pos.y);
}

sf::Vector2f getPosAtBlock(int x, int y) {
    return sf::Vector2f(x * Constants::BLOCK_SIZE, (Constants::WORLD_HEIGHT - y) * Constants::BLOCK_SIZE);
}

sf::Vector2f getItemBlockScale(const sf::Vector2f scale) {
    return getItemScale(scale, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
}

sf::Vector2f getItemScale(sf::Vector2f scale, const int height, const int width) {
    scale.x = (scale.x / width) * Constants::HOTBAR_SLOT_SIZE;
    scale.y = (scale.y / height) * Constants::HOTBAR_SLOT_SIZE;

    return scale;
}

bool doesBlockExist(const std::vector<std::vector<Block*>>& world, const int x, const int y) {
    if (x < 0 || y < 0 || y >= world.size() || x > world[y].size()) return false;

    return world[y][x] != nullptr && !world[y][x]->isBlockAir();
}

sf::Text* createText(const std::string& textStr, const int fontSize) {
    sf::Text* text = new sf::Text(minecraftFont);
    text->setString(textStr);
    text->setFillColor(sf::Color::White);
    text->setOutlineColor(sf::Color::Black);
    text->setCharacterSize(fontSize);

    return text;
}
