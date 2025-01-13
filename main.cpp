#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/blocks/Dirt.h"
#include "include/blocks/Stone.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"
#include "include/terrain/ValueNoise.h"

using namespace std;
using namespace sf;

int main() {

    const int WORLD_WIDTH = 10;
    const int WORLD_HEIGHT = 10;
    const int BLOCK_SIZE = 63;

    vector<vector<Block*>> world(WORLD_HEIGHT, vector<Block*>(WORLD_WIDTH));
    ValueNoise valueNoise(256, BLOCK_SIZE);
    valueNoise.generateTerrain(world, WORLD_WIDTH, WORLD_HEIGHT);

    RenderWindow window(VideoMode({800, 600}), "Minecraft", Style::Titlebar | Style::Close);

    auto* steve = new Steve();

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
                window.close();
            }

            if (ev.has_value()) {
                steve->moveSprite(ev.value());
            }
        }

        steve->update();
        window.clear();

        for (int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                if (!world[y][x]->isBlockAir()) {
                    window.draw(world[y][x]->getSprite().value());
                }
            }
        }

        window.draw(steve->getSprite().value());
        window.display();
    }

    return 0;
}