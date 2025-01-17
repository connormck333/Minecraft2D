#pragma once

#ifndef VALUE_NOISE_H
#define VALUE_NOISE_H
#include <vector>
#include "../blocks/Block.h"

class ValueNoise {
private:
    const int GRID_SIZE;

    std::vector<float> generateRandomGradients() const;

    float fade(float t);

    float lerp(float a, float b, float t);

    float valueNoise(float x, const std::vector<float>& gradients);

    float fractalNoise(float x, int octaves, float persistence, const std::vector<float>& gradients);

public:
    ValueNoise(int gridSize);

    void generateTerrain(std::vector<std::vector<Block*>>& world);
};

#endif //VALUE_NOISE_H
