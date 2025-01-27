#include "../../../include/inventory/crafting/CraftItem.h"
#include "../../../include/inventory/items/WoodItem.h"

CraftItem::CraftItem(const std::string& fileName) : Item("wood_pickaxe", "CraftItems/" + fileName) {
    craftBox = sf::RectangleShape();
    craftBox.setFillColor(sf::Color(210, 210, 210, 100));
    craftBox.setOutlineColor(sf::Color::White);
    craftBox.setOutlineThickness(4);
    craftBox.setSize({125, 150});
}

void CraftItem::addRequirement(Item* requirement) {
    craftRequirements.push_back(requirement);
}

void CraftItem::render(sf::RenderWindow& window, const sf::Vector2f pos) {
    craftBox.setPosition(pos);
    window.draw(craftBox);

    sprite.value().setPosition(sf::Vector2f(pos.x + 15, pos.y + 15));
    window.draw(sprite.value());

    sf::Vector2f currentItemPos = {pos.x + 5, pos.y + 117};
    for (Item* item : craftRequirements) {
        item->getSprite().value().setPosition(currentItemPos);
        window.draw(item->getSprite().value());

        item->getQuantityText().value().setPosition({currentItemPos.x + 2, currentItemPos.y + 10});
        window.draw(item->getQuantityText().value());

        currentItemPos.x += 20;
    }
}

