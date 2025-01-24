#include "../../include/screens/RespawnScreen.h"

#include "../../include/Constants.h"
#include "../../include/Utils.h"

RespawnScreen::RespawnScreen(sf::RenderWindow &window) : window(window) {
    background = sf::RectangleShape(sf::Vector2f(Constants::SCREEN_HEIGHT, Constants::SCREEN_WIDTH));
    background.setFillColor(sf::Color(25, 0,0, 200));

    text = createText("You died!", 40);
}

void RespawnScreen::render() {
    background.setPosition(window.mapPixelToCoords(sf::Vector2i(0, 0)));
    text->setPosition(window.mapPixelToCoords(sf::Vector2i(
        (Constants::SCREEN_WIDTH / 2),
        300
    )));
    window.draw(background);
    window.draw(*text);
}

