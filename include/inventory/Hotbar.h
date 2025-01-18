#pragma once

#ifndef HOTBAR_H
#define HOTBAR_H

#include "../sprites/GameSprite.h"

class Hotbar : public GameSprite {
public:
    Hotbar();

    void updatePosition(const sf::RenderWindow& window);
};

#endif //HOTBAR_H
