#include "../../include/handlers/RespawnHandler.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"

RespawnHandler::RespawnHandler(sf::RenderWindow& window, Steve& steve, Hotbar& hotbar) : steve(steve), hotbar(hotbar) {
    respawnScreen = new RespawnScreen(window);
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
    }
}

