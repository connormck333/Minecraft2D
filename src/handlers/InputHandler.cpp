#include "../../include/handlers/InputHandler.h"

InputHandler::InputHandler(Steve& steve, Hotbar& hotbar) : steve(steve), hotbar(hotbar) {
    cooldownClock.start();

    numKeys.push_back(sf::Keyboard::Key::Num1);
    numKeys.push_back(sf::Keyboard::Key::Num2);
    numKeys.push_back(sf::Keyboard::Key::Num3);
    numKeys.push_back(sf::Keyboard::Key::Num4);
    numKeys.push_back(sf::Keyboard::Key::Num5);
    numKeys.push_back(sf::Keyboard::Key::Num6);
    numKeys.push_back(sf::Keyboard::Key::Num7);
    numKeys.push_back(sf::Keyboard::Key::Num8);
}

void InputHandler::handle() {
    // Check for movement
    if (isKeyPressed(sf::Keyboard::Key::D) && !isKeyPressed(sf::Keyboard::Key::A)) {
        steve.animateWalking(Direction::RIGHT);
    } else if (!isKeyPressed(sf::Keyboard::Key::D) && isKeyPressed(sf::Keyboard::Key::A)) {
        steve.animateWalking(Direction::LEFT);
    } else if (isKeyPressed(sf::Keyboard::Key::I) && cooldownClock.getElapsedTime().asMilliseconds() > COOLDOWN) {
        inventoryOpen = !inventoryOpen;
        cooldownClock.restart();
    } else if (isKeyPressed(sf::Keyboard::Key::X) && cooldownClock.getElapsedTime().asMilliseconds() > COOLDOWN) {
        hotbar.dropSelectedItem();
        cooldownClock.restart();
    } else if (isKeyPressed(sf::Keyboard::Key::C) && cooldownClock.getElapsedTime().asMilliseconds() > COOLDOWN) {
        hotbar.dropOneOfSelectedItem();
        cooldownClock.restart();
    }

    // Check for selected inventory slot change
    for (int i = 0; i < numKeys.size(); i++) {
        if (isKeyPressed(numKeys[i])) {
            hotbar.setSelectedSlot(i);
        }
    }
}

bool InputHandler::isInventoryOpen() const {
    return inventoryOpen;
}
