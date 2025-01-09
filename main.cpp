#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "My window", Style::Titlebar | Style::Close);
    Font font;
    font.openFromFile("../assets/fonts/Roboto-Regular.ttf");
    Text text(font, "Hello World!");

    while (window.isOpen()) {
        // Event Polling
        while (const optional<Event> ev = window.pollEvent()) {
            if (ev->is<Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}