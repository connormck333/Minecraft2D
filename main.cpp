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
using namespace sf;

int main() {

    vector<vector<Block*>> world(Constants::WORLD_HEIGHT, vector<Block*>(Constants::WORLD_WIDTH));
    ValueNoise valueNoise(512);
    valueNoise.generateTerrain(world);

    RenderWindow window(VideoMode({800, 600}), "Minecraft", Style::Titlebar | Style::Close);
    View view = window.getDefaultView();

    sf::Vector2f stevePos = getSteveSpawnPos(world);
    auto* steve = new Steve(stevePos);

    EventHandler eventHandler(window, *steve, world);
    InputHandler inputHandler(*steve);
    WorldGenerator worldGenerator(window, *steve, world);
    worldGenerator.loadTrees();

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
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