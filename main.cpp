#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/Constants.h"
#include "include/handlers/EventHandler.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"
#include "include/terrain/ValueNoise.h"
#include "include/Utils.h"
#include "include/handlers/InputHandler.h"
#include "include/terrain/WorldGenerator.h"

using namespace std;

int main() {

    vector<vector<Block*>> world(Constants::WORLD_HEIGHT, vector<Block*>(Constants::WORLD_WIDTH));
    ValueNoise valueNoise(10);
    valueNoise.generateTerrain(world);

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Minecraft", sf::Style::Titlebar | sf::Style::Close);
    sf::View view = window.getDefaultView();

    sf::Vector2f stevePos = getSteveSpawnPos(world);
    auto* steve = new Steve(stevePos);

    EventHandler eventHandler(window, *steve, world);
    InputHandler inputHandler(*steve);
    WorldGenerator worldGenerator(window, *steve, world);
    worldGenerator.loadTrees();

    while (window.isOpen()) {

        while (const optional<sf::Event> ev = window.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }

            eventHandler.handleEvents(ev);
        }

        inputHandler.handle();

        steve->update();
        view.setCenter(steve->getSprite().value().getPosition());
        window.setView(view);

        window.clear();

        worldGenerator.updateWorld();

        window.draw(steve->getSprite().value());
        window.display();
    }

    return 0;
}