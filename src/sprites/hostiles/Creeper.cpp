#include "../../../include/sprites/hostiles/Creeper.h"

#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

Creeper::Creeper(std::vector<std::vector<Block*>>& world, SpriteHandler& spriteHandler, Steve &steve, sf::Vector2f pos)
: AutomatedSprite(steve, "creeper.png", Constants::HOSTILE_MOVEMENT_SPEED, Constants::CREEPER_HEALTH),
world(world), spriteHandler(spriteHandler) {
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

    explodingTextures[0] = sf::IntRect(
        {31, 149},
        {13, 18}
    );
    explodingTextures[1] = sf::IntRect(
        {55, 149},
        {13, 18}
    );
    explodingTextures[2] = sf::IntRect(
        {78, 149},
        {13, 18}
    );
    explodingTextures[3] = sf::IntRect(
        {102, 149},
        {13, 18}
    );
    explodingTextures[4] = sf::IntRect(
        {125, 149},
        {13, 18}
    );
    explodingTextures[5] = sf::IntRect(
        {149, 149},
        {13, 18}
    );
}

void Creeper::update() {
    if (exploding) {
        explode();
        return;
    }

    shouldJump();

    sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());
    sf::Vector2f spritePos = getRelativeBlockPos(sprite.value().getPosition());

    if (abs(stevePos.x - spritePos.x) <= 1 && abs(stevePos.y - spritePos.y) <= 1) {
        explode();
    } else {
        Direction dir = getDirectionOfSteve();
        animateWalking(dir);
    }

    GroundSprite::update();
}

void Creeper::explode() {
    if (!exploding) {
        exploding = true;
        explodingClock.restart();
    }

    int nextTexture;
    int millisPassed = explodingClock.getElapsedTime().asMilliseconds();
    if (millisPassed <= 200) nextTexture = 0;
    else if (millisPassed <= 400) nextTexture = 1;
    else if (millisPassed <= 600) nextTexture = 2;
    else if (millisPassed <= 800) nextTexture = 3;
    else if (millisPassed <= 1000) nextTexture = 4;
    else nextTexture = 5;

    sprite.value().setTextureRect(explodingTextures[nextTexture]);

    if (millisPassed > 1000) {
        exploding = false;
        destroyWorld();
    }
}

void Creeper::destroyWorld() {
    const sf::Vector2f pos = getRelativeBlockPos(sprite.value().getPosition());

    for (int yOffset = -2; yOffset <= 2; yOffset++) {
        for (int xOffset = -2; xOffset <= 2; xOffset++) {
            const int y = static_cast<int>(pos.y) + yOffset;
            const int x = static_cast<int>(pos.x) + xOffset;
            if (const Block* temp = world[y][x]; temp != nullptr && !temp->isBlockAir()) {
                world[y][x] = new Block();
                delete temp;
            }
        }
    }

    const sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());
    if (abs(stevePos.x - pos.x) <= 3 && abs(stevePos.y - pos.y) <= 3) {
        steve.damage(4, getSpriteDirection(stevePos, pos));
    }

    spriteHandler.removeSprite(this);
    GameSprite::~GameSprite();
}

