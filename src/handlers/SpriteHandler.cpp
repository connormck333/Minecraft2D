#include "../../include/handlers/SpriteHandler.h"

#include "../../include/Constants.h"
#include "../../include/Utils.h"
#include "../../include/sprites/hostiles/Creeper.h"
#include "../../include/sprites/hostiles/Zombie.h"

SpriteHandler::SpriteHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>>& world, Steve& steve)
: window(window), world(world), steve(steve) {
    spriteClock.start();
}

void SpriteHandler::addSprite(GameSprite* sprite) {
    sprites.push_back(sprite);
}

Steve& SpriteHandler::getSteve() const {
    return steve;
}

std::vector<GameSprite*> SpriteHandler::getSprites() const {
    std::vector<GameSprite*> spritesVector = sprites;
    spritesVector.push_back(&steve);

    return spritesVector;
}

void SpriteHandler::update() {
    steve.update();
    for (GameSprite* sprite : sprites) {
        if (auto groundSprite = dynamic_cast<GroundSprite*>(sprite)) {
            groundSprite->update();
        }
    }

    if (sprites.size() >= Constants::MAX_MOB_AMOUNT) return;

    if (spriteClock.getElapsedTime().asSeconds() >= Constants::MOB_SPAWN_RATE_SECONDS) {
        createNewSprite();
        spriteClock.restart();
    }
}

void SpriteHandler::draw() const {
    window.draw(steve.getSprite().value());
    for (GameSprite* sprite : sprites) {
        if (!sprite->getSprite().has_value()) continue;
        window.draw(sprite->getSprite().value());
    }
}

void SpriteHandler::removeSprite(GameSprite* sprite) {
    int index = -1;
    for (int i = 0; i < sprites.size(); i++) {
        if (sprite == sprites[i]) {
            index = i;
        }
    }

    if (index != -1) {
        sprites.erase(sprites.begin() + index);
    }
}

void SpriteHandler::createNewSprite() {
    sf::Vector2f pos = createSpritePos();
    int randNum = getRandomInt(0, 1);

    std::cout << "new sprite: " << pos.x << ", " << pos.y << std::endl;
    if (randNum == 0) {
        sprites.push_back(new Zombie(steve, pos));
    } else {
        sprites.push_back(new Creeper(world, *this, steve, pos));
    }
}

sf::Vector2f SpriteHandler::createSpritePos() const {
    sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());
    sf::Vector2f newPos;
    Direction dir = steve.getDirectionFacing();

    newPos.x = dir == Direction::LEFT ? stevePos.x - 5 : stevePos.x + 5;
    newPos.y = findTopYLevelAtX(world, newPos.x) + 2;

    return getPosAtBlock(newPos.x, newPos.y);
}
