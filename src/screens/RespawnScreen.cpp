#include "../../include/screens/RespawnScreen.h"

#include "../../include/Constants.h"
#include "../../include/Utils.h"

RespawnScreen::RespawnScreen(sf::RenderWindow& window) : Screen(window) {
    background.setFillColor(sf::Color(25, 0,0, 200));
    text = createText("You died!", 40);
}

void RespawnScreen::render() {
    Screen::render();
    text->setPosition(window.mapPixelToCoords(sf::Vector2i(
        (Constants::SCREEN_WIDTH / 2),
        300
    )));
    window.draw(*text);
}

