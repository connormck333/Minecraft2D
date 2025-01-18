#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../include/blocks/Block.h"

sf::Vector2f getSteveSpawnPos(const std::vector<std::vector<Block*>>& world);

Block* getRandomOre(sf::Vector2f pos);

int getRandomInt(int min, int max);
bool getRandomBool(int chance);

int findTopYLevelAtX(const std::vector<std::vector<Block*>>& world, int x);

sf::Vector2f getRelativeBlockPos(float x, float y);

#endif //UTILS_H
