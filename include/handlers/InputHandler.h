#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../inventory/Hotbar.h"
#include "../sprites/Steve.h"

class InputHandler {
private:
    Steve& steve;
    Hotbar& hotbar;

    std::vector<sf::Keyboard::Key> numKeys;

public:
    InputHandler(Steve& steve, Hotbar& hotbar);

    void handle() const;
};

#endif //INPUTHANDLER_H
