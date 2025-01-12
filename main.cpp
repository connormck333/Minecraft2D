#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/blocks/Dirt.h"
#include "include/blocks/Grass.h"
#include "include/blocks/Stone.h"
#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "My window", Style::Titlebar | Style::Close);

    auto* steve = new Steve();
    auto* grass = new Grass();
    auto* dirt = new Dirt();
    auto* stone = new Stone();

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
                window.close();
            }

            if (ev.has_value()) {
                steve->moveSprite(ev.value());
            }
        }

        grass->collidesWith(steve);
        steve->update();

        window.clear();
        window.draw(steve->getSprite().value());
        window.draw(grass->getSprite().value());
        window.draw(dirt->getSprite().value());
        window.draw(stone->getSprite().value());
        window.display();
    }

    return 0;
}