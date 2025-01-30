#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../include/blocks/Block.h"

inline sf::Font quantityFont("assets/fonts/Roboto-Regular.ttf");
inline sf::Font minecraftFont("assets/fonts/MinecraftRegular.otf");

sf::Vector2f getSteveSpawnPos(const std::vector<std::vector<Block*>>& world);

Block* getRandomOre(sf::Vector2f pos);

int getRandomInt(int min, int max);
bool getRandomBool(int chance);

int findTopYLevelAtX(const std::vector<std::vector<Block*>>& world, int x);

sf::Vector2f getRelativeBlockPos(float x, float y);
sf::Vector2f getRelativeBlockPos(sf::Vector2f pos);
sf::Vector2f getPosAtBlock(int x, int y);

Direction getSpriteDirection(sf::Vector2f stevePos, sf::Vector2f spritePos);

sf::Vector2f getItemBlockScale(sf::Vector2f scale);
sf::Vector2f getItemScale(sf::Vector2f scale, int height, int width);

bool doesBlockExist(const std::vector<std::vector<Block*>>& world, int x, int y);

sf::Text* createText(const std::string& textStr, int fontSize);

#endif //UTILS_H
