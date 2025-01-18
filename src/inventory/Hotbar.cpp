#include "../../include/inventory/Hotbar.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"

Hotbar::Hotbar(sf::RenderWindow& window) : GameSprite("hotbar.png"), window(window) {
    for (int i = 0; i < 8; i++) slots.push_back(nullptr);

    loadRect(4, 4, Constants::HOTBAR_HEIGHT, Constants::HOTBAR_WIDTH);
}

void Hotbar::update(const std::string& itemId) {
    addNewItem(itemId);
    updatePosition();
    updateSlots();
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
        std::cout << i << std::endl;

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

void Hotbar::draw() const {
    if (sprite.has_value()) {
        window.draw(sprite.value());

        for (Item* item : slots) {
            if (item == nullptr) continue;
            window.draw(item->getSprite().value());
        }
    }
}

