#include "../../include/handlers/EventHandler.h"
#include "../../include/Utils.h"

EventHandler::EventHandler(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world) :
    window(window), steve(steve), world(world) {}


std::string EventHandler::handleEvents(const std::optional<sf::Event>& ev) const {
    if (!ev.has_value()) return nullptr;

    steve.handleEvent(ev.value());
    std::string itemId = deleteBlockOnClick(ev.value());

    return itemId;
}

std::string EventHandler::deleteBlockOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2f pos = window.mapPixelToCoords(mouse->position);
        sf::Vector2f relativePos = getRelativeBlockPos(pos.x, pos.y);

        if (int y = relativePos.y; y > 0 && y < world.size()) {
            if (int x = relativePos.x; x >= 0 && x < world[y].size()) {
                const Block* block = world[y][x];
                world[y][x] = new Block();

                std::string itemId = block->getItem();

                delete block;
                return itemId;
            }
        }
    }

    return "-1";
}

