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
    const int WORLD_HEIGHT = 20;
    const int BLOCK_SIZE = 63;

    vector<vector<Block*>> world(WORLD_HEIGHT, vector<Block*>(WORLD_WIDTH));
    ValueNoise valueNoise(512, BLOCK_SIZE);
    valueNoise.generateTerrain(world, WORLD_WIDTH, WORLD_HEIGHT);

    RenderWindow window(VideoMode({800, 600}), "Minecraft", Style::Titlebar | Style::Close);
    View view = window.getDefaultView();

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
        view.setCenter(steve->getSprite().value().getPosition());
        window.setView(view);

        window.clear();
        bool isOnGround = false;
        bool rightBlocked = false;
        bool leftBlocked = false;
        for (int y = 0; y < WORLD_HEIGHT; y++) {
            for (int x = 0; x < WORLD_WIDTH; x++) {
                if (!world[y][x]->isBlockAir()) {
                    window.draw(world[y][x]->getSprite().value());
                }
                if (CollisionType* collision = world[y][x]->collidesWith(steve)) {
                    isOnGround = isOnGround || collision->collisionY();
                    if (collision->collisionX()) {
                        if (!rightBlocked && collision->getDirection() == Direction::RIGHT) rightBlocked = true;
                        if (!leftBlocked && collision->getDirection() == Direction::LEFT) leftBlocked = true;
                    }
                    steve->setSpriteOnGround(true);
                }
            }
        }

        if (!isOnGround) steve->setSpriteOnGround(false);

        steve->setLeftBlocked(leftBlocked);
        steve->setRightBlocked(rightBlocked);

        window.draw(steve->getSprite().value());
        window.display();
    }

    return 0;
}