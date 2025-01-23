#include "../../include/blocks/Block.h"

#include "../../include/Constants.h"
#include "../../include/Utils.h"
#include "../../include/blocks/utils/CollisionType.h"
#include "../../include/sprites/AutomatedSprite.h"
#include "../../include/sprites/GroundSprite.h"

Block::Block(const std::string& fileName) : GameSprite(fileName) {}

Block::Block() : GameSprite("") {
    isAir = true;
}

void Block::loadBlock(int x, int y) {
    loadRect(x, y, Constants::BLOCK_SIZE, Constants::BLOCK_SIZE);
}

CollisionType* Block::collidesWith(GroundSprite* other) const {
    if (isAir) return nullptr;

    sf::FloatRect otherHitbox = other->getHitbox();
    sf::FloatRect blockBounds = sprite->getGlobalBounds();
    std::optional<sf::FloatRect> intersection;

    if ((intersection = otherHitbox.findIntersection(blockBounds))) {
        sf::FloatRect intersectionValue = intersection.value();

        sf::Vector2f otherPos = getRelativeBlockPos(other->getSprite().value().getPosition());
        sf::Vector2f blockPos = getRelativeBlockPos(sprite->getPosition());

        bool collisionX = intersectionValue.size.y > 1 && intersectionValue.size.x > 0;
        bool collisionY = otherPos.y - 1 == blockPos.y && intersectionValue.size.y > 0 && intersectionValue.size.x > 6;
        bool collisionTop = intersectionValue.size.y > 0 && intersectionValue.size.x > 4 && (otherHitbox.position.y > blockBounds.position.y);
        Direction direction = (otherHitbox.position.x > blockBounds.position.x) ? Direction::LEFT : Direction::RIGHT;

        return new CollisionType(collisionX, collisionY, collisionTop, direction);
    }

    return nullptr;
}

bool Block::isBlockAir() const {
    return isAir;
}

Item* Block::getItem() const {
    return nullptr;
}
