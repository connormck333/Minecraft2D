#include "../../include/terrain/WorldGenerator.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"
#include "../../include/blocks/Block.h"
#include "../../include/blocks/utils/CollisionType.h"
#include "../../include/terrain/Tree.h"

WorldGenerator::WorldGenerator(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world) :
    window(window), steve(steve), world(world) {}

void WorldGenerator::loadTrees() const {
    int min = 0;
    int max = Constants::WORLD_WIDTH / Constants::TREES_AMOUNT;
    for (int i = 0; i < Constants::TREES_AMOUNT; i++) {
        int x = getRandomInt(min, max);
        int y = findTopYLevelAtX(world, x);

        new Tree(world, sf::Vector2f(x, y));

        min = max;
        max += Constants::WORLD_WIDTH / Constants::TREES_AMOUNT;
    }
}

void WorldGenerator::updateWorld() const {
    bool isOnGround = false;
    bool rightBlocked = false;
    bool leftBlocked = false;
    bool hitHead = false;

    sf::Vector2f stevePos = steve.getSprite().value().getPosition();
    stevePos.y = Constants::WORLD_HEIGHT - (stevePos.y / Constants::BLOCK_SIZE) + 1;
    stevePos.x = stevePos.x / Constants::BLOCK_SIZE;

    const int minY = std::max(0, static_cast<int>(stevePos.y) - 7);
    const int maxY = std::max(0, static_cast<int>(stevePos.y) + 7);
    const int minX = std::max(0, static_cast<int>(stevePos.x) - 8);
    const int maxX = std::max(0, static_cast<int>(stevePos.x) + 8);

    for (int y = minY; y < maxY; y++) {
        for (int x = minX; x < maxX; x++) {
            if (!world[y][x]->isBlockAir()) {
                window.draw(world[y][x]->getSprite().value());
            }

            if ((y < minY || y > maxY) && (x < minX || x > maxX)) {
                continue;
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

