#include "../../include/terrain/ValueNoise.h"

#include "../../include/blocks/Grass.h"
#include "../../include/blocks/Dirt.h"
#include "../../include/blocks/Stone.h"

using namespace std;

ValueNoise::ValueNoise(int gridSize, int blockSize) : GRID_SIZE(gridSize), BLOCK_SIZE(blockSize) {}

void ValueNoise::generateTerrain(std::vector<std::vector<Block*>>& world, const int WORLD_WIDTH, const int WORLD_HEIGHT, const int AIR_HEIGHT) {
    auto gradients = generateRandomGradients();

    for (int x = 0; x < WORLD_WIDTH; x++) {
        float noiseValue = fractalNoise(x * 0.1f, 4, 0.5f, gradients);
        int terrainHeight = static_cast<int>((noiseValue + 1.0f) * (WORLD_HEIGHT / 4));

        for (int y = 0; y < WORLD_HEIGHT; y++) {
            if (y > terrainHeight) {
                world[y][x] = new Block();
                continue;
            }

            sf::Vector2f pos = sf::Vector2f(x * BLOCK_SIZE, (y + AIR_HEIGHT) * BLOCK_SIZE);

            if (y == terrainHeight) {
                world[y][x] = new Stone(pos);
            } else if (y >= terrainHeight - 2)  {
                world[y][x] = new Dirt(pos);
            } else {
                world[y][x] = new Grass(pos);
            }

            world[y][x]->getSprite().value().setPosition(sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE));
        }
    }
}

vector<float> ValueNoise::generateRandomGradients() const {
    vector<float> gradients(GRID_SIZE);
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < GRID_SIZE; i++) {
        gradients[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    return gradients;
}

float ValueNoise::fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float ValueNoise::lerp(float a, float b, float t) {
    return a + t * (b - a);
}

float ValueNoise::valueNoise(float x, const std::vector<float> &gradients) {
    int x0 = static_cast<int>(floor(x)) % GRID_SIZE;
    int x1 = (x0 + 1) % GRID_SIZE;

    float g0 = gradients[x0];
    float g1 = gradients[x1];

    float t = x - floor(x);
    float fadeT = fade(t);

    return lerp(g0, g1, fadeT);
}

float ValueNoise::fractalNoise(float x, int octaves, float persistence, const std::vector<float> &gradients) {
    float total = 0.0f;
    float frequency = 10.0f;
    float amplitude = 50.0f;
    float maxValue = 0.0f;

    for (int i = 0; i < octaves; i++) {
        total += valueNoise(x * frequency, gradients) * amplitude;

        maxValue += amplitude;
        amplitude *= persistence;
        frequency *= 2.0f;
    }

    return total / maxValue;
}