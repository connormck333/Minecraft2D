#include "../../include/handlers/SpriteHandler.h"

SpriteHandler::SpriteHandler(sf::RenderWindow& window, Steve& steve) : window(window), steve(steve) {}

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

void SpriteHandler::update() const {
    steve.update();
    for (GameSprite* sprite : sprites) {
        if (auto groundSprite = dynamic_cast<GroundSprite*>(sprite)) {
            groundSprite->update();
        }
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
