#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Constants.h"
#include "include/handlers/EventHandler.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"
#include "include/terrain/ValueNoise.h"
#include "include/Utils.h"
#include "include/handlers/InputHandler.h"
#include "include/handlers/SpriteHandler.h"
#include "include/inventory/Healthbar.h"
#include "include/inventory/Hotbar.h"
#include "include/terrain/WorldGenerator.h"
#include "include/GameState.h"
#include "include/handlers/RespawnHandler.h"
#include "include/screens/CraftScreen.h"

using namespace std;

int main() {

    vector<vector<Block*>> world(Constants::WORLD_HEIGHT, vector<Block*>(Constants::WORLD_WIDTH));
    ValueNoise valueNoise(30);
    valueNoise.generateTerrain(world);

    sf::RenderWindow window(sf::VideoMode({Constants::SCREEN_HEIGHT, Constants::SCREEN_WIDTH}), "Minecraft", sf::Style::Titlebar | sf::Style::Close);
    sf::View view = window.getDefaultView();

    sf::Vector2f stevePos = getSteveSpawnPos(world);
    auto* steve = new Steve(stevePos);
    auto* hotbar = new Hotbar(window);
    auto* healthbar = new Healthbar(window, steve->getHealth());

    CraftScreen craftScreen(window);
    RespawnHandler respawnHandler(window, *steve, *hotbar);
    auto gameState = GameState::ACTIVE;

    SpriteHandler spriteHandler(window, world, *steve);
    EventHandler eventHandler(window, world, *steve, *hotbar, spriteHandler, craftScreen);
    InputHandler inputHandler(*steve, *hotbar);
    WorldGenerator worldGenerator(window, spriteHandler, world);
    worldGenerator.loadTrees();

    while (window.isOpen()) {

        // Check for events
        while (const optional<sf::Event> ev = window.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }

            if (gameState == GameState::ACTIVE) eventHandler.handleEvents(ev, inputHandler.isInventoryOpen());
        }

        // Check if Steve's health is <= 0
        respawnHandler.checkForDeath(gameState);

        // Manage game depending on GameState
        if (gameState == GameState::ACTIVE) {
            inputHandler.handle();

            spriteHandler.update();
            hotbar->update();

            view.setCenter(steve->getSprite().value().getPosition());
            window.setView(view);
        } else respawnHandler.respawn(world, gameState);

        // Clear window
        window.clear();

        // Redraw world depending on Steve's location
        worldGenerator.updateWorld();

        // Redraw Steve, hotbar and healthbar
        spriteHandler.draw();
        hotbar->draw();
        healthbar->update();

        // Display respawn screen if Steve is dead
        respawnHandler.render(gameState);

        // Display crafting screen if inventory is open
        if (inputHandler.isInventoryOpen()) craftScreen.render();

        window.display();
    }

    return 0;
}