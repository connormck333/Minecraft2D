#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../include/blocks/Block.h"

sf::Vector2f getSteveSpawnPos(const std::vector<std::vector<Block*>>& world);

#endif //UTILS_H
