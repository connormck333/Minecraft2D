#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Constants.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"
#include "include/terrain/ValueNoise.h"
#include "include/Utils.h"

using namespace std;
using namespace sf;

int main() {

    vector<vector<Block*>> world(Constants::WORLD_HEIGHT, vector<Block*>(Constants::WORLD_WIDTH));
    ValueNoise valueNoise(512, Constants::BLOCK_SIZE);
    valueNoise.generateTerrain(world, Constants::WORLD_WIDTH, Constants::WORLD_HEIGHT);

    RenderWindow window(VideoMode({800, 600}), "Minecraft", Style::Titlebar | Style::Close);
    View view = window.getDefaultView();

    sf::Vector2f stevePos = getSteveSpawnPos(world);
    auto* steve = new Steve(stevePos);

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
                window.close();
            }

            if (ev.has_value()) {
                steve->handleEvent(ev.value());
                if (const auto mouse = ev.value().getIf<Event::MouseButtonPressed>()) {
                    Vector2f pos = window.mapPixelToCoords(mouse->position);
                    int x = pos.x / Constants::BLOCK_SIZE;
                    int y = abs((pos.y / Constants::BLOCK_SIZE) - Constants::WORLD_HEIGHT) + 1;

                    if (y >= 0 && y < world.size()) {
                        if (x >= 0 && x < world[y].size()) {
                            const Block* temp = world[y][x];
                            world[y][x] = new Block();

                            delete temp;
                        }
                    }
                }
            }
        }

        if (isKeyPressed(sf::Keyboard::Key::D) && !isKeyPressed(sf::Keyboard::Key::A)) {
            steve->animateWalking(Direction::RIGHT);
        } else if (!isKeyPressed(sf::Keyboard::Key::D) && isKeyPressed(sf::Keyboard::Key::A)) {
            steve->animateWalking(Direction::LEFT);
        }

        steve->update();
        view.setCenter(steve->getSprite().value().getPosition());
        window.setView(view);

        window.clear();
        bool isOnGround = false;
        bool rightBlocked = false;
        bool leftBlocked = false;
        bool hitHead = false;
        for (int y = 0; y < Constants::WORLD_HEIGHT; y++) {
            for (int x = 0; x < Constants::WORLD_WIDTH; x++) {
                if (!world[y][x]->isBlockAir()) {
                    window.draw(world[y][x]->getSprite().value());
                }
                if (CollisionType* collision = world[y][x]->collidesWith(steve)) {
                    hitHead = collision->collisionTop();
                    isOnGround = isOnGround || (collision->collisionY() && !hitHead);
                    if (collision->collisionX()) {
                        if (!rightBlocked && collision->getDirection() == Direction::RIGHT) rightBlocked = true;
                        if (!leftBlocked && collision->getDirection() == Direction::LEFT) leftBlocked = true;
                    }
                    steve->setSpriteOnGround(true);
                }
            }
        }

        if (!isOnGround) steve->setSpriteOnGround(false);
        if (hitHead) steve->setSpriteJumping(false);

        steve->setLeftBlocked(leftBlocked);
        steve->setRightBlocked(rightBlocked);

        window.draw(steve->getSprite().value());
        window.display();
    }

    return 0;
}