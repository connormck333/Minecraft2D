#include "../../../include/inventory/items/Item.h"
#include "../../../include/Constants.h"

Item::Item(std::string id, int slotId, const std::string &fileName) : GameSprite(fileName), id(id), slotId(slotId), quantity(1) {}

std::string Item::getId() const {
    return id;
}

sf::Vector2i Item::getSlotPosition()  {
    sf::Vector2i pos;
    pos.x = Constants::HOTBAR_POSITION.x + Constants::HOTBAR_SLOT_XPOS[slotId];
    pos.y = Constants::HOTBAR_POSITION.y + Constants::HOTBAR_SLOT_YPOS;

    return pos;
}

void Item::setSlotPosition(const sf::RenderWindow& window) {
    sprite->setPosition(window.mapPixelToCoords(getSlotPosition()));
}

void Item::incrementQuantity() {
    quantity++;
}

void Item::decrementQuantity() {
    quantity--;
}

