#include "../../include/inventory/Hotbar.h"
#include "../../include/Constants.h"

Hotbar::Hotbar() : GameSprite("hotbar.png") {
    loadRect(4, 4, Constants::HOTBAR_HEIGHT, Constants::HOTBAR_WIDTH);
}

void Hotbar::updatePosition(const sf::RenderWindow &window) {
    sf::Vector2f pos = window.mapPixelToCoords(Constants::HOTBAR_POSITION);
    sprite->setPosition(pos);
}
