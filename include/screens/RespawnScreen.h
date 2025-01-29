#pragma once

#ifndef RESPAWNSCREEN_H
#define RESPAWNSCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"

class RespawnScreen final : public Screen {
private:
    sf::Text* text;

public:
    explicit RespawnScreen(sf::RenderWindow& window);

    void render() override;
};

#endif //RESPAWNSCREEN_H
