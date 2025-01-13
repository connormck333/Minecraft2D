#include "../../include/blocks/Block.h"
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

bool Block::collidesWith(GroundSprite* other) const {
    sf::Sprite otherSprite = other->getSprite().value();

    if (otherSprite.getGlobalBounds().findIntersection(sprite->getGlobalBounds())) {
        other->setSpriteOnGround(true);
        return true;
    }

    other->setSpriteOnGround(false);
    return false;
}

bool Block::isBlockAir() const {
    return isAir;
}
