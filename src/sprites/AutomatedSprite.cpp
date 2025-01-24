#include "../../include/sprites/AutomatedSprite.h"
#include "../../include/Utils.h"

AutomatedSprite::AutomatedSprite(Steve& steve, const std::string& fileName, float movementSpeed)
: GroundSprite(fileName, movementSpeed), steve(steve), damageCooldown(1) {
    damageClock.restart();
}

Direction AutomatedSprite::getDirectionOfSteve() const {
    sf::Vector2f stevePos = steve.getSprite().value().getPosition();
    sf::Vector2f spritePos = sprite.value().getPosition();

    return stevePos.x < spritePos.x ? Direction::LEFT : Direction::RIGHT;
}

void AutomatedSprite::update() {
    sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());
    sf::Vector2f spritePos = getRelativeBlockPos(sprite.value().getPosition());

    if (stevePos.x != spritePos.x) {
        Direction dir = getDirectionOfSteve();
        animateWalking(dir);
    } else if (stevePos.y == spritePos.y) {
        if (damageClock.getElapsedTime().asSeconds() >= damageCooldown) {
            steve.damage(1);
            damageClock.restart();
        }
    }

    GroundSprite::update();
}

void AutomatedSprite::shouldJump() {
    if (leftBlocked || rightBlocked) {
        if (shouldAttemptJump) jump();
        else resetToStillTexture();
    }
}
