#include "../../include/inventory/Healthbar.h"

Healthbar::Healthbar(sf::RenderWindow& window) : window(window), health(5) {
    for (int i = 0; i < 5; i++) {
        hearts.push_back(new GameSprite("heart.png"));
    }
}

void Healthbar::update() const {
    for (int i = 0; i < health; i++) {
        sf::Sprite heart = hearts[i]->getSprite().value();
        heart.setScale(sf::Vector2f(0.05, 0.05));
        heart.setPosition(window.mapPixelToCoords(sf::Vector2i((i * 65), 10)));

        window.draw(heart);
    }
}
