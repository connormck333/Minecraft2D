#include "../../include/screens/CraftScreen.h"

#include "../../include/inventory/crafting/WoodPickaxe.h"

CraftScreen::CraftScreen(sf::RenderWindow& window) : Screen(window) {
    items.push_back(new WoodPickaxe());
}

void CraftScreen::render() {
    Screen::render();
    sf::Vector2f currentPos = window.mapPixelToCoords({20, 20});
    for (CraftItem* item : items) {
        item->render(window, currentPos);
    }
}

