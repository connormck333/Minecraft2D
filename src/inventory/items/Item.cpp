#include "../../../include/inventory/items/Item.h"
#include "../../../include/Constants.h"
#include "../../../include/Utils.h"

Item::Item(std::string id, int slotId, const std::string &fileName) : GameSprite(fileName), id(id), slotId(slotId), quantity(1) {
    quantityText = sf::Text(quantityFont);
    quantityText->setString(std::to_string(quantity));
    quantityText->setCharacterSize(15);
    quantityText->setFillColor(sf::Color::White);
}

std::string Item::getId() const {
    return id;
}

std::optional<sf::Text> Item::getQuantityText() const {
    return quantityText;
}

sf::Vector2i Item::getSlotPosition() const {
    sf::Vector2i pos;
    pos.x = Constants::HOTBAR_POSITION.x + Constants::HOTBAR_SLOT_XPOS[slotId];
    pos.y = Constants::HOTBAR_POSITION.y + Constants::HOTBAR_SLOT_YPOS;

    return pos;
}

void Item::setSlotPosition(const sf::RenderWindow& window) {
    sf::Vector2f pos = window.mapPixelToCoords(getSlotPosition());
    sprite->setPosition(pos);
    pos.y += 10;
    quantityText.value().setPosition(pos);
}

void Item::incrementQuantity() {
    quantity++;
    quantityText.value().setString(std::to_string(quantity));
}

void Item::decrementQuantity() {
    quantity--;
    quantityText.value().setString(std::to_string(quantity));
}

Block* Item::createBlock(const sf::Vector2f& pos) {
    return new Block();
}
