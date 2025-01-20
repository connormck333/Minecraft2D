#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Constants.h"
#include "include/handlers/EventHandler.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"
#include "include/terrain/ValueNoise.h"
#include "include/Utils.h"
#include "include/handlers/InputHandler.h"
#include "include/inventory/Hotbar.h"
#include "include/terrain/WorldGenerator.h"

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

    EventHandler eventHandler(window, *steve, world);
    InputHandler inputHandler(*steve, *hotbar);
    WorldGenerator worldGenerator(window, *steve, world);
    worldGenerator.loadTrees();

    while (window.isOpen()) {

        std::string itemId;

        while (const optional<sf::Event> ev = window.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }

            itemId = eventHandler.handleEvents(ev);
        }

        inputHandler.handle();

        steve->update();
        hotbar->update(itemId);

        view.setCenter(steve->getSprite().value().getPosition());
        window.setView(view);

        window.clear();

        worldGenerator.updateWorld();

        window.draw(steve->getSprite().value());
        hotbar->draw();
        window.display();
    }

    return 0;
}