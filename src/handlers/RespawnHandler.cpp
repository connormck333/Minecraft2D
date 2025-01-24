#include "../../include/handlers/RespawnHandler.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"

RespawnHandler::RespawnHandler(sf::RenderWindow& window, Steve& steve, Hotbar& hotbar)
: window(window), steve(steve), hotbar(hotbar) {
    respawnScreen = new RespawnScreen(window);
    currentTimeText = createText("0s", 30);
}

void RespawnHandler::checkForDeath(GameState& gameState) {
    if (steve.getHealth() <= 0 && gameState != GameState::RESPAWN) {
        gameState = GameState::RESPAWN;
        respawnClock.restart();
    }
}

void RespawnHandler::respawn(const std::vector<std::vector<Block*>>& world, GameState& gameState) const {
    float remainingTime = Constants::RESPAWN_TIME - respawnClock.getElapsedTime().asSeconds();
    if (remainingTime <= 0) {
        gameState = GameState::ACTIVE;
        steve.respawn(getSteveSpawnPos(world));
    }
}

void RespawnHandler::render(const GameState& gameState) const {
    if (gameState == GameState::RESPAWN) {
        respawnScreen->render();
    } else {
        currentTimeText->setString(std::to_string(static_cast<int>(respawnClock.getElapsedTime().asSeconds())) + "s");
        currentTimeText->setPosition(window.mapPixelToCoords(sf::Vector2i(Constants::SCREEN_WIDTH + 100, 10)));
        window.draw(*currentTimeText);
    }
}

