#include "../../include/handlers/EventHandler.h"
#include "../../include/Constants.h"

EventHandler::EventHandler(sf::RenderWindow& window, Steve& steve, std::vector<std::vector<Block*>>& world) :
    window(window), steve(steve), world(world) {}


void EventHandler::handleEvents(const std::optional<sf::Event>& ev) const {
    if (!ev.has_value()) return;

    steve.handleEvent(ev.value());
    deleteBlockOnClick(ev.value());
}

void EventHandler::deleteBlockOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2f pos = window.mapPixelToCoords(mouse->position);
        int x = pos.x / Constants::BLOCK_SIZE;
        int y = abs((pos.y / Constants::BLOCK_SIZE) - Constants::WORLD_HEIGHT) + 1;

        if (y >= 0 && y < world.size()) {
            if (x >= 0 && x < world[y].size()) {
                const Block* temp = world[y][x];
                world[y][x] = new Block();

                delete temp;
            }
        }
    }
}
