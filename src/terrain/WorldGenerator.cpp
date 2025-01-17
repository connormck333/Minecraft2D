#include "../../include/terrain/WorldGenerator.h"
#include "../../include/Constants.h"
#include "../../include/blocks/Block.h"

class CollisionType;
WorldGenerator::WorldGenerator(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world) :
    window(window), steve(steve), world(world) {}

void WorldGenerator::updateWorld() {
    bool isOnGround = false;
    bool rightBlocked = false;
    bool leftBlocked = false;
    bool hitHead = false;

    for (int y = 0; y < Constants::WORLD_HEIGHT; y++) {
        for (int x = 0; x < Constants::WORLD_WIDTH; x++) {
            if (!world[y][x]->isBlockAir()) {
                window.draw(world[y][x]->getSprite().value());
            }
            if (CollisionType* collision = world[y][x]->collidesWith(&steve)) {
                hitHead = collision->collisionTop();
                isOnGround = isOnGround || (collision->collisionY() && !hitHead);
                if (collision->collisionX()) {
                    if (!rightBlocked && collision->getDirection() == Direction::RIGHT) rightBlocked = true;
                    if (!leftBlocked && collision->getDirection() == Direction::LEFT) leftBlocked = true;
                }
                steve.setSpriteOnGround(true);
            }
        }
    }

    if (!isOnGround) steve.setSpriteOnGround(false);
    if (hitHead) steve.setSpriteJumping(false);

    steve.setLeftBlocked(leftBlocked);
    steve.setRightBlocked(rightBlocked);
}

