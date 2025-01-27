#include <utility>

#include "../../../include/inventory/items/Item.h"
#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

Item::Item(std::string id, const std::string &fileName) : GameSprite(fileName), id(std::move(id)), quantity(1) {
    quantityText = sf::Text(quantityFont);
    quantityText->setString(std::to_string(quantity));
    quantityText->setCharacterSize(15);
    quantityText->setFillColor(sf::Color::White);
}

Item::Item(std::string id, const std::string &fileName, const bool isBlock) : Item(id, fileName) {
    this->isBlock = isBlock;
}

std::string Item::getId() const {
    return id;
}

std::optional<sf::Text>& Item::getQuantityText() {
    return quantityText;
}

sf::Vector2i Item::getSlotPosition(const int slotId) const {
    sf::Vector2i pos;
    pos.x = Constants::HOTBAR_POSITION.x + Constants::HOTBAR_SLOT_XPOS[slotId];
    pos.y = Constants::HOTBAR_POSITION.y + Constants::HOTBAR_SLOT_YPOS;

    return pos;
}

void Item::setSlotPosition(const sf::RenderWindow& window, const int slotId) {
    sf::Vector2f pos = window.mapPixelToCoords(getSlotPosition(slotId));
    sprite->setPosition(pos);
    pos.y += 10;
    quantityText.value().setPosition(pos);
}

void Item::incrementQuantity() {
    quantity++;
    setQuantityText();
}

void Item::decrementQuantity() {
    quantity--;
    setQuantityText();
}

void Item::setQuantity(int quantity) {
    this->quantity = quantity;
    setQuantityText();
}

int Item::getQuantity() const {
    return quantity;
}

bool Item::canBePlaced() const {
    return isBlock;
}

Block* Item::createBlock(const sf::Vector2f& pos) {
    return new Block();
}

void Item::setQuantityText() {
    quantityText.value().setString(std::to_string(quantity));
}
