#include "../../include/blocks/Block.h"

#include "../../include/blocks/utils/CollisionType.h"
#include "../../include/sprites/GroundSprite.h"

Block::Block(const std::string& fileName) : GameSprite(fileName) {}

Block::Block() : GameSprite("") {
    isAir = true;
}

void Block::loadBlock(int x, int y, int height, int width) {
    const sf::IntRect blockRect(
        {x, y},
        {width, height}
    );
    sprite->setTextureRect(blockRect);
}

CollisionType* Block::collidesWith(GroundSprite* other) const {
    if (isAir) return nullptr;

    sf::FloatRect otherHitbox = other->getHitbox();
    sf::FloatRect blockBounds = sprite->getGlobalBounds();
    std::optional<sf::FloatRect> intersection;

    if ((intersection = otherHitbox.findIntersection(blockBounds))) {
        sf::FloatRect intersectionValue = intersection.value();

        bool collisionX = intersectionValue.size.y > 1 && intersectionValue.size.x > 0;
        bool collisionY = intersectionValue.size.y > 0 && intersectionValue.size.x > 4;
        bool collisionTop = collisionY && (otherHitbox.position.y > blockBounds.position.y);
        Direction direction = (otherHitbox.position.x > blockBounds.position.x) ? Direction::LEFT : Direction::RIGHT;

        return new CollisionType(collisionX, collisionY, collisionTop, direction);
    }

    return nullptr;
}

bool Block::isBlockAir() const {
    return isAir;
}
