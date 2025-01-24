#include "../../include/screens/RespawnScreen.h"

#include "../../include/Constants.h"

RespawnScreen::RespawnScreen(sf::RenderWindow &window) : window(window) {
    background = sf::RectangleShape(sf::Vector2f(Constants::SCREEN_HEIGHT, Constants::SCREEN_WIDTH));
    background.setFillColor(sf::Color(25, 0,0, 200));

    font = sf::Font("assets/fonts/MinecraftRegular.otf");
    text = new sf::Text(font);
    text->setString("You died!");
    text->setFillColor(sf::Color::White);
    text->setOutlineColor(sf::Color::Black);
    text->setCharacterSize(40);
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

