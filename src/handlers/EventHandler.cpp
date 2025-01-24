#include "../../include/handlers/EventHandler.h"
#include "../../include/Utils.h"
#include "../../include/Constants.h"

EventHandler::EventHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>>& world, Steve& steve, Hotbar& hotbar) :
    window(window), world(world), steve(steve), hotbar(hotbar) {}


void EventHandler::handleEvents(const std::optional<sf::Event>& ev) const {
    if (!ev.has_value()) return;

    steve.handleEvent(ev.value());
    deleteBlockOnClick(ev.value());
    placeBlockOnRightClick(ev.value());
}

void EventHandler::deleteBlockOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Left) return;

        sf::Vector2f pos = getMousePos(mouse);
        sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
                if (canBreakOrPlaceBlock(pos.x, pos.y, stevePos.x, stevePos.y)) {
                    const Block* block = world[y][x];
                    world[y][x] = new Block();

                    if (!block->isBlockAir()) {
                        hotbar.addNewItem(block->getItem());
                    }

                    delete block;
                }
            }
        }
    }
}

void EventHandler::placeBlockOnRightClick(const sf::Event &ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Right) return;
        if (hotbar.getSelectedItem() == nullptr || !hotbar.getSelectedItem()->canBePlaced()) return;

        sf::Vector2f pos = getMousePos(mouse);
        sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
                if (
                    world[y][x] == nullptr
                    || !world[y][x]->isBlockAir()
                    || !canBreakOrPlaceBlock(x, y, stevePos.x, stevePos.y)
                ) return;

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

bool EventHandler::canBreakOrPlaceBlock(int x, int y, int steveX, int steveY) const {

    if (!isWithinDistance(x, y, steveX, steveY)) return false;

    bool canInteractX = true;
    if (steveX < x) {
        for (int currentX = steveX + 1; currentX < x; currentX++) {
            if (doesBlockExist(world, currentX, y)) canInteractX = false;
        }
    } else {
        for (int currentX = x + 1; currentX < steveX; currentX++) {
            if (doesBlockExist(world, currentX, y)) canInteractX = false;
        }
    }

    bool canInteractY = true;
    if (steveY < y) {
        for (int currentY = steveY + 1; currentY < y; currentY++) {
            if (doesBlockExist(world, x, currentY)) canInteractY = false;
        }
    } else {
        for (int currentY = y + 1; currentY < steveY; currentY++) {
            if (doesBlockExist(world, x, currentY)) canInteractY = false;
        }
    }

    return canInteractX && canInteractY;
}

bool EventHandler::isWithinDistance(int x, int y, int steveX, int steveY) const {
    return std::abs(steveX - x) <= Constants::STEVE_REACH_DISTANCE && std::abs(steveY - y) <= Constants::STEVE_REACH_DISTANCE;
}

