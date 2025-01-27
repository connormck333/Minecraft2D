#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../inventory/Hotbar.h"
#include "../sprites/Steve.h"

class InputHandler {
private:
    Steve& steve;
    Hotbar& hotbar;

    const int COOLDOWN = 200;
    sf::Clock cooldownClock;
    std::vector<sf::Keyboard::Key> numKeys;
    bool inventoryOpen = false;

public:
    InputHandler(Steve& steve, Hotbar& hotbar);

    void handle();

    [[nodiscard]] bool isInventoryOpen() const;
};

#endif //INPUTHANDLER_H
