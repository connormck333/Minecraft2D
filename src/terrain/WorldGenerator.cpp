#include "../../include/terrain/WorldGenerator.h"

#include <unordered_set>

#include "../../include/Constants.h"
#include "../../include/Utils.h"
#include "../../include/blocks/Block.h"
#include "../../include/blocks/utils/CollisionType.h"
#include "../../include/terrain/Tree.h"

WorldGenerator::WorldGenerator(sf::RenderWindow& window, SpriteHandler& spriteHandler, std::vector<std::vector<Block*>>& world) :
    window(window), spriteHandler(spriteHandler), world(world) {}

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
    std::vector<GameSprite*> sprites = spriteHandler.getSprites();
    Steve& steve = spriteHandler.getSteve();

    std::unordered_set<GroundSprite*> isOnGround;
    std::unordered_set<GroundSprite*> rightBlocked;
    std::unordered_set<GroundSprite*> leftBlocked;
    std::unordered_set<GroundSprite*> hitHead;

    sf::Vector2f stevePos = steve.getSprite().value().getPosition();
    sf::Vector2f pos = getRelativeBlockPos(stevePos.x, stevePos.y);

    const int minY = std::max(0, static_cast<int>(pos.y) - 7);
    const int maxY = std::max(0, static_cast<int>(pos.y) + 7);
    const int minX = std::max(0, static_cast<int>(pos.x) - 8);
    const int maxX = std::max(0, static_cast<int>(pos.x) + 8);

    std::vector<GroundSprite*> groundSprites = getGroundSprites(sprites, minX, minY, maxX, maxY);

    for (int y = minY; y < maxY; y++) {
        for (int x = minX; x < maxX; x++) {
            if (!world[y][x]->isBlockAir()) {
                window.draw(world[y][x]->getSprite().value());
            }

            if ((y < minY || y > maxY) && (x < minX || x > maxX)) {
                continue;
            }

            for (GroundSprite* sprite : groundSprites) {
                if (CollisionType* collision = world[y][x]->collidesWith(sprite)) {
                    if (collision->collisionTop()) hitHead.insert(sprite);
                    if (isOnGround.contains(sprite) || (collision->collisionY() && !hitHead.contains(sprite))) isOnGround.insert(sprite);

                    if (collision->collisionX()) {
                        if (!rightBlocked.contains(sprite) && collision->getDirection() == Direction::RIGHT) rightBlocked.insert(sprite);
                        if (!leftBlocked.contains(sprite) && collision->getDirection() == Direction::LEFT) leftBlocked.insert(sprite);
                    }
                }
                sprite->setSpriteOnGround(true);
            }
        }
    }

    for (GroundSprite* sprite : groundSprites) {
        if (!isOnGround.contains(sprite)) sprite->setSpriteOnGround(false);
        if (hitHead.contains(sprite)) sprite->setSpriteJumping(false);

        sprite->setLeftBlocked(leftBlocked.contains(sprite));
        sprite->setRightBlocked(rightBlocked.contains(sprite));
    }
}

std::vector<GroundSprite*> WorldGenerator::getGroundSprites(std::vector<GameSprite*>& sprites, int minX, int minY, int maxX, int maxY) const {
    std::vector<GroundSprite*> groundSprites;
    for (GameSprite* gameSprite : sprites) {
        if (auto* sprite = dynamic_cast<GroundSprite*>(gameSprite)) {
            sf::Vector2f pos = sprite->getSprite().value().getPosition();
            sf::Vector2f spritePos = getRelativeBlockPos(pos.x, pos.y);
            if (
                spritePos.x <= maxX && spritePos.x >= minX
                && spritePos.y <= maxY && spritePos.y >= minY
            ) {
                groundSprites.push_back(sprite);
                continue;
            }
            sprite->setSpriteOnGround(true);
        }
    }

    return groundSprites;
}