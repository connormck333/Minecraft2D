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
#include "include/inventory/Hotbar.h"
#include "include/sprites/hostiles/Zombie.h"
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

    EventHandler eventHandler(window, world, *steve, *hotbar);
    InputHandler inputHandler(*steve, *hotbar);
    SpriteHandler spriteHandler(window, *steve);
    WorldGenerator worldGenerator(window, spriteHandler, world);
    worldGenerator.loadTrees();
    spriteHandler.addSprite(new Zombie(stevePos));

    while (window.isOpen()) {

        while (const optional<sf::Event> ev = window.pollEvent()) {
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }

            eventHandler.handleEvents(ev);
        }

        inputHandler.handle();

        spriteHandler.update();
        hotbar->update();

        view.setCenter(steve->getSprite().value().getPosition());
        window.setView(view);

        window.clear();

        worldGenerator.updateWorld();

        spriteHandler.draw();
        hotbar->draw();
        window.display();
    }

    return 0;
}