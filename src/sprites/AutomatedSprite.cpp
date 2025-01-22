#include "../../include/sprites/AutomatedSprite.h"

AutomatedSprite::AutomatedSprite(Steve& steve, const std::string& fileName, float movementSpeed)
: GroundSprite(fileName, movementSpeed), steve(steve) {}

Direction AutomatedSprite::getDirectionOfSteve() const {
    sf::Vector2f stevePos = steve.getSprite().value().getPosition();
    sf::Vector2f spritePos = sprite.value().getPosition();

    return stevePos.x < spritePos.x ? Direction::LEFT : Direction::RIGHT;
}

void AutomatedSprite::update() {
    Direction dir = getDirectionOfSteve();
    animateWalking(dir);

    if ((leftBlocked || rightBlocked) && shouldAttemptJump) {
        jump();
    }

    GroundSprite::update();
}