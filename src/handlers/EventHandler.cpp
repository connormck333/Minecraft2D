#include "../../include/handlers/EventHandler.h"
#include "../../include/Utils.h"
#include "../../include/Constants.h"

EventHandler::EventHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>>& world, Steve& steve, Hotbar& hotbar) :
    window(window), world(world), steve(steve), hotbar(hotbar) {}


std::string EventHandler::handleEvents(const std::optional<sf::Event>& ev) const {
    if (!ev.has_value()) return nullptr;

    steve.handleEvent(ev.value());
    std::string itemId = deleteBlockOnClick(ev.value());
    placeBlockOnRightClick(ev.value());

    return itemId;
}

std::string EventHandler::deleteBlockOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Left) return "-1";

        sf::Vector2f pos = getMousePos(mouse);

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
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

void EventHandler::placeBlockOnRightClick(const sf::Event &ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Right) return;

        sf::Vector2f pos = getMousePos(mouse);

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
                if (world[y][x] == nullptr || !world[y][x]->isBlockAir()) return;

                sf::Vector2f relativePos(
                    x * Constants::BLOCK_SIZE,
                    (Constants::WORLD_HEIGHT - y) * Constants::BLOCK_SIZE
                );
                world[y][x] = hotbar.getSelectedItem()->createBlock(relativePos);

                hotbar.getSelectedItem()->decrementQuantity();
            }
        }
    }
}


sf::Vector2f EventHandler::getMousePos(const sf::Event::MouseButtonPressed* mouse) const {
    sf::Vector2f pos = window.mapPixelToCoords(mouse->position);
    return getRelativeBlockPos(pos.x, pos.y);
}

