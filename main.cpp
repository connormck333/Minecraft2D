#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "include/sprites/GameSprite.h"
#include "include/sprites/Steve.h"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "My window", Style::Titlebar | Style::Close);

    auto* steve = new Steve();

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
                window.close();
            }

            steve->moveSprite();
        }

        window.clear();
        window.draw(steve->getSprite().value());
        window.display();
    }

    return 0;
}