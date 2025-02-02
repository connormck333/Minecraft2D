#include "../../include/inventory/Hotbar.h"
#include "../../include/Constants.h"
#include "../../include/Utils.h"
#include "../../include/inventory/items/tools/PickaxeItem.h"

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

bool Hotbar::update() {
    updatePosition();
    updateSelectedSlot();
    bool gameOver = updateSlots();

    return gameOver;
}

void Hotbar::addNewItem(Item* item) {
    if (item == nullptr) return;

    for (int i = 0; i < 8; i++) {
        if (slots[i] == nullptr) continue;

        if (slots[i]->getId() == item->getId()) {
            slots[i]->incrementQuantity();
            return;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (slots[i] != nullptr) continue;

        slots[i] = item;
        return;
    }
}

bool Hotbar::addNewItem(CraftItem* item) {
    std::vector<Item*> requirements = item->getRequirements();

    for (const Item* requirement : requirements) {
        bool valid = false;
        for (int i = 0; i < slots.size(); i++) {
            Item* slotItem = slots[i];
            if (slotItem == nullptr) continue;
            if (slotItem->getId() == requirement->getId() && slotItem->getQuantity() >= requirement->getQuantity()) {
                valid = true;
                int newQuantity = slotItem->getQuantity() - requirement->getQuantity();
                if (newQuantity == 0) {
                    deleteSlot(i);
                } else {
                    slotItem->setQuantity(newQuantity);
                }
                break;
            }
        }

        if (!valid) return false;
    }

    addNewItem(item->getHotbarItem());

    return true;
}

void Hotbar::updatePosition() {
    sf::Vector2f pos = window.mapPixelToCoords(Constants::HOTBAR_POSITION);
    sprite->setPosition(pos);
}

bool Hotbar::updateSlots() {
    int emeraldCount = 0;
    for (int i = 0; i < slots.size(); i++) {
        Item* item = slots[i];
        if (item == nullptr) continue;

        // Check quantity is greater than 0
        if (item->getQuantity() <= 0) {
            deleteSlot(i);
            continue;
        }

        // Check pickaxe durability
        if (const auto* pickaxe = dynamic_cast<PickaxeItem*>(item)) {
            if (pickaxe->getDurability() <= 0) {
                deleteSlot(i);
                continue;
            }
        }

        // Check for emeralds
        if (item->getId() == "emerald") emeraldCount += item->getQuantity();

        item->setSlotPosition(window, i);
    }

    return emeraldCount >= Constants::EMERALD_WIN_COUNT;
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

Item* Hotbar::getSelectedItem() const {
    return slots[selectedSlot];
}

void Hotbar::dropSelectedItem() {
    deleteSlot(selectedSlot);
}

void Hotbar::dropOneOfSelectedItem() {
    slots[selectedSlot]->decrementQuantity();
    if (slots[selectedSlot]->getQuantity() <= 0) deleteSlot(selectedSlot);
}

void Hotbar::deleteSlot(int slotId) {
    const Item* temp = slots[slotId];
    slots[slotId] = nullptr;
    delete temp;
}