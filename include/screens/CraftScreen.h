#pragma once

#ifndef CRAFTSCREEN_H
#define CRAFTSCREEN_H

#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "../inventory/crafting/CraftItem.h"

class CraftScreen final : public Screen {
private:
    std::vector<CraftItem*> items;

public:
    explicit CraftScreen(sf::RenderWindow& window);

    void render() override;
};

#endif //CRAFTSCREEN_H
