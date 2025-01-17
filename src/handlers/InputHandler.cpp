#include "../../include/handlers/InputHandler.h"

InputHandler::InputHandler(Steve& steve) : steve(steve) {}

void InputHandler::handle() const {
    if (isKeyPressed(sf::Keyboard::Key::D) && !isKeyPressed(sf::Keyboard::Key::A)) {
        steve.animateWalking(Direction::RIGHT);
    } else if (!isKeyPressed(sf::Keyboard::Key::D) && isKeyPressed(sf::Keyboard::Key::A)) {
        steve.animateWalking(Direction::LEFT);
    }
}

