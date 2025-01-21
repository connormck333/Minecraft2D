#include "../../../include/sprites/hostiles/Zombie.h"
#include "../../../include/Constants.h"

Zombie::Zombie(Steve& steve, sf::Vector2f pos) : AutomatedSprite(steve, "zombie.png", Constants::HOSTILE_MOVEMENT_SPEED) {
    textures[0] = sf::IntRect(
        {17, 79},
        {15, 16}
    );
    currentTexture = 0;
    sprite->setTextureRect(textures[0]);

    sprite->setPosition(pos);
    sprite->setOrigin({ sprite->getLocalBounds().size.x - 11.5f, 0 });
    sprite->setScale(sf::Vector2f(5, 5));
    directionFacing = Direction::RIGHT;

    setHitboxPositionAndSize(30, 60, 50, 50);

    createTextures();
}

void Zombie::createTextures() {
    textures[1] = sf::IntRect(
        {17, 127},
        {13, 15}
    );
    textures[2] = sf::IntRect(
        {42, 127},
        {13, 15}
    );
    textures[3] = sf::IntRect(
        {65, 127},
        {14, 15}
    );
    textures[4] = sf::IntRect(
        {89, 127},
        {14, 15}
    );
}