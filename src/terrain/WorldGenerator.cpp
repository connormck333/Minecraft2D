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
    stevePos.y = Constants::WORLD_HEIGHT - (stevePos.y / Constants::BLOCK_SIZE);
    stevePos.x = stevePos.x / Constants::BLOCK_SIZE;
    int minY = stevePos.y - 5;
    int maxY = stevePos.y + 5;
    int minX = stevePos.x - 5;
    int maxX = stevePos.x + 5;

    for (int y = 0; y < Constants::WORLD_HEIGHT; y++) {
        for (int x = 0; x < Constants::WORLD_WIDTH ; x++) {
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

