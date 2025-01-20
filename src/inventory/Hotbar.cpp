#include "../../include/inventory/Hotbar.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"

Hotbar::Hotbar(sf::RenderWindow& window) : GameSprite("hotbar.png"), window(window) {
    for (int i = 0; i < 8; i++) slots.push_back(nullptr);

    loadSelectedSlot();
    loadRect(4, 4, Constants::HOTBAR_HEIGHT, Constants::HOTBAR_WIDTH);
}

void Hotbar::loadSelectedSlot() {
    selectedSquare = sf::RectangleShape(sf::Vector2f(42, 39));
    selectedSquare.setFillColor(sf::Color::Transparent);
    selectedSquare.setOutlineThickness(4);
    selectedSquare.setOutlineColor(sf::Color::White);
}

void Hotbar::update(const std::string& itemId) {
    addNewItem(itemId);
    updatePosition();
    updateSlots();
    updateSelectedSlot();
}

void Hotbar::addNewItem(const std::string& itemId) {
    if (itemId == "-1" || itemId.size() == 0) return;

    for (int i = 0; i < 8; i++) {
        if (slots[i] == nullptr) continue;

        if (slots[i]->getId() == itemId) {
            slots[i]->incrementQuantity();
            return;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (slots[i] != nullptr) continue;

        slots[i] = getItemById(itemId, i);
        return;
    }
}

void Hotbar::updatePosition() {
    sf::Vector2f pos = window.mapPixelToCoords(Constants::HOTBAR_POSITION);
    sprite->setPosition(pos);
}

void Hotbar::updateSlots() const {
    for (Item* item : slots) {
        if (item == nullptr) continue;
        item->setSlotPosition(window);
    }
}

void Hotbar::updateSelectedSlot() {
    const sf::Vector2i pos(
        Constants::HOTBAR_POSITION.x + Constants::HOTBAR_SLOT_XPOS[selectedSlot] - 7,
        Constants::HOTBAR_POSITION.y + Constants::HOTBAR_SLOT_YPOS - 7
    );
    selectedSquare.setPosition(window.mapPixelToCoords(pos));
}

void Hotbar::draw() const {
    if (!sprite.has_value()) return;

    window.draw(sprite.value());
    window.draw(selectedSquare);

    for (Item* item : slots) {
        if (item == nullptr) continue;
        window.draw(item->getSprite().value());
        if (item->getQuantityText().has_value()) {
            window.draw(item->getQuantityText().value());
        }
    }
}

void Hotbar::setSelectedSlot(int slotId) {
    selectedSlot = slotId;
}

Item *Hotbar::getSelectedItem() const {
    return slots[selectedSlot];
}

