#include "../../include/screens/GameOverScreen.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"

GameOverScreen::GameOverScreen(sf::RenderWindow& window, RespawnHandler& respawnHandler)
: Screen(window), respawnHandler(respawnHandler) {
    background.setFillColor(sf::Color(0, 10, 0, 200));
    winningMessage = createText("You win!", 40);
}

void GameOverScreen::render() {
    Screen::render();
    winningMessage->setPosition(window.mapPixelToCoords(sf::Vector2i(
        (Constants::SCREEN_WIDTH / 2),
        300
    )));
    window.draw(*winningMessage);

    respawnHandler.stopTimeAliveClock();

    const std::string timeElapsed = "Time taken: " + std::to_string(respawnHandler.getTimeAliveSeconds()) + "s";
    sf::Text* timeMessage = createText(timeElapsed, 25);
    timeMessage->setPosition(window.mapPixelToCoords(sf::Vector2i(
        (Constants::SCREEN_WIDTH / 2),
        350
    )));
    window.draw(*timeMessage);
}
