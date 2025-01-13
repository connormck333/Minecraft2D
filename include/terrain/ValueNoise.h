#pragma once

#ifndef VALUE_NOISE_H
#define VALUE_NOISE_H
#include <vector>
#include "../blocks/Block.h"

class ValueNoise {
private:
    const int GRID_SIZE;
    const int BLOCK_SIZE;

    std::vector<float> generateRandomGradients() const;

    float fade(float t);

    float lerp(float a, float b, float t);

    float valueNoise(float x, const std::vector<float>& gradients);

    float fractalNoise(float x, int octaves, float persistence, const std::vector<float>& gradients);

public:
    ValueNoise(int gridSize, int blockSize);

    void generateTerrain(std::vector<std::vector<Block*>>& world, int WORLD_WIDTH, int WORLD_HEIGHT);
};

#endif //VALUE_NOISE_H
