#include "../../../include/sprites/hostiles/Creeper.h"

#include "../../../include/Constants.h"

Creeper::Creeper(Steve &steve, sf::Vector2f pos) : AutomatedSprite(steve, "creeper.png", Constants::HOSTILE_MOVEMENT_SPEED) {
    textures[0] = sf::IntRect(
            {31, 56},
            {10, 15}
        );
    currentTexture = 0;
    sprite->setTextureRect(textures[0]);

    sprite->setPosition(pos);
    sprite->setOrigin({ sprite->getLocalBounds().size.x / 3, 0 });
    sprite->setScale(sf::Vector2f(5, 5));
    directionFacing = Direction::RIGHT;

    createTextures();
}

void Creeper::createTextures() {
    textures[1] = sf::IntRect(
        {31, 104},
        {10, 15}
    );
    textures[2] = sf::IntRect(
        {54, 104},
        {10, 15}
    );
    textures[3] = sf::IntRect(
        {79, 104},
        {10, 15}
    );
    textures[4] = sf::IntRect(
        {103, 104},
        {10, 15}
    );
}