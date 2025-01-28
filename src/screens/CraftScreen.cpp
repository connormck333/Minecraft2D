#include "../../include/screens/CraftScreen.h"

#include "../../include/inventory/crafting/DiamondPickaxe.h"
#include "../../include/inventory/crafting/DiamondSword.h"
#include "../../include/inventory/crafting/GoldPickaxe.h"
#include "../../include/inventory/crafting/GoldSword.h"
#include "../../include/inventory/crafting/IronPickaxe.h"
#include "../../include/inventory/crafting/IronSword.h"
#include "../../include/inventory/crafting/StonePickaxe.h"
#include "../../include/inventory/crafting/StoneSword.h"
#include "../../include/inventory/crafting/WoodPickaxe.h"
#include "../../include/inventory/crafting/WoodSword.h"

CraftScreen::CraftScreen(sf::RenderWindow& window) : Screen(window) {
    items.push_back(new WoodPickaxe());
    items.push_back(new StonePickaxe());
    items.push_back(new IronPickaxe());
    items.push_back(new GoldPickaxe());
    items.push_back(new DiamondPickaxe());
    items.push_back(new WoodSword());
    items.push_back(new StoneSword());
    items.push_back(new IronSword());
    items.push_back(new GoldSword());
    items.push_back(new DiamondSword());
}

std::vector<CraftItem*>& CraftScreen::getItems() {
    return items;
}

void CraftScreen::render() {
    Screen::render();
    sf::Vector2f currentPos = window.mapPixelToCoords({20, 20});
    const float originalX = currentPos.x;

    for (int i = 0; i < items.size(); i++) {
        if (i % 5 == 0 && i != 0) {
            currentPos.y += 175;
            currentPos.x = originalX;
        }
        CraftItem* item = items[i];
        item->render(window, currentPos);
        currentPos.x += 150;
    }
}

