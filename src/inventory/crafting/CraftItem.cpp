#include "../../../include/inventory/crafting/CraftItem.h"
#include "../../../include/inventory/items/WoodItem.h"

CraftItem::CraftItem(const std::string& id, const std::string& fileName) : Item(id, "CraftItems/" + fileName) {
    craftBox = sf::RectangleShape();
    craftBox.setFillColor(sf::Color(210, 210, 210, 100));
    craftBox.setOutlineColor(sf::Color::White);
    craftBox.setOutlineThickness(4);
    craftBox.setSize({125, 150});

    craftClock.start();
}

void CraftItem::addRequirement(Item* requirement) {
    craftRequirements.push_back(requirement);
}

std::vector<Item*>& CraftItem::getRequirements() {
    return craftRequirements;
}

sf::Vector2f CraftItem::getBoxPos() const {
    return craftBox.getPosition();
}

sf::Vector2f CraftItem::getBoxSize() const {
    return craftBox.getSize();
}

void CraftItem::setBoxRed() {
    craftBox.setFillColor(sf::Color(210, 0, 0, 100));
    craftClock.restart();
}

void CraftItem::resetBoxColor() {
    int timeElapsed = craftClock.getElapsedTime().asMilliseconds();
    if (timeElapsed < 1000 || timeElapsed > 2000) return;

    craftBox.setFillColor(sf::Color(210, 210, 210, 100));
}

Item* CraftItem::getHotbarItem() {
    return nullptr;
}

void CraftItem::render(sf::RenderWindow& window, const sf::Vector2f pos) {
    craftBox.setPosition(pos);
    resetBoxColor();
    window.draw(craftBox);

    sprite.value().setPosition(sf::Vector2f(pos.x + 15, pos.y + 15));
    window.draw(sprite.value());

    sf::Vector2f currentItemPos = {pos.x + 5, pos.y + 117};
    for (Item* item : craftRequirements) {
        item->getSprite().value().setPosition(currentItemPos);
        window.draw(item->getSprite().value());

        item->getQuantityText().value().setPosition({currentItemPos.x + 2, currentItemPos.y + 10});
        window.draw(item->getQuantityText().value());

        currentItemPos.x += 40;
    }
}

