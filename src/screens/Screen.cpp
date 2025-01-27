#include "../../include/screens/Screen.h"
#include "../../include/Constants.h"

Screen::Screen(sf::RenderWindow& window) : window(window) {
    background = sf::RectangleShape(sf::Vector2f(Constants::SCREEN_HEIGHT, Constants::SCREEN_WIDTH));
    background.setFillColor(sf::Color(0, 0, 0, 200));
}

void Screen::render() {
    background.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));
    window.draw(background);
}
