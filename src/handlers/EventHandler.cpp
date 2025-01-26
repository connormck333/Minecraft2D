#include "../../include/handlers/EventHandler.h"
#include "../../include/Utils.h"
#include "../../include/Constants.h"

EventHandler::EventHandler(sf::RenderWindow& window, std::vector<std::vector<Block*>>& world, Steve& steve, Hotbar& hotbar, SpriteHandler& spriteHandler) :
    window(window), world(world), steve(steve), hotbar(hotbar), spriteHandler(spriteHandler) {}


void EventHandler::handleEvents(const std::optional<sf::Event>& ev) const {
    if (!ev.has_value()) return;

    steve.handleEvent(ev.value());
    deleteBlockOnClick(ev.value());
    placeBlockOnRightClick(ev.value());
    damageSpriteOnClick(ev.value());
}

void EventHandler::deleteBlockOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Left) return;

        sf::Vector2f pos = getMousePos(mouse);
        sf::Vector2f stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
                if (canBreakBlock(pos.x, pos.y, stevePos.x, stevePos.y)) {
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

        const auto pos = sf::Vector2i(getMousePos(mouse));
        const auto stevePos = sf::Vector2i(getRelativeBlockPos(steve.getSprite().value().getPosition()));

        if (int y = pos.y; y > 0 && y < world.size()) {
            if (int x = pos.x; x >= 0 && x < world[y].size()) {
                if (
                    world[y][x] == nullptr
                    || !world[y][x]->isBlockAir()
                    || !canBreakBlock(x, y, stevePos.x, stevePos.y)
                    || !canPlaceBlock(pos.x, pos.y)
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

bool EventHandler::canBreakBlock(int x, int y, int steveX, int steveY) const {

    if (!isWithinReach(x, y, steveX, steveY)) return false;

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

bool EventHandler::canPlaceBlock(int x, int y) const {
    return doesBlockExist(world, x + 1, y)
        || doesBlockExist(world, x, y + 1)
        || doesBlockExist(world, x, y - 1)
        || doesBlockExist(world, x - 1, y);
}

void EventHandler::damageSpriteOnClick(const sf::Event& ev) const {
    if (const auto mouse = ev.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouse->button != sf::Mouse::Button::Left) return;
        if (!steve.canAttack()) return;

        auto mousePos = getRelativeBlockPos(window.mapPixelToCoords(mouse->position));
        auto stevePos = getRelativeBlockPos(steve.getSprite().value().getPosition());
        Direction clickDir = getSpriteDirection(stevePos, mousePos);
        std::vector<GameSprite*> sprites = spriteHandler.getSprites(false);

        for (const auto& sprite : sprites) {
            if (auto* groundSprite = dynamic_cast<GroundSprite*>(sprite)) {
                sf::Vector2f spritePos = getRelativeBlockPos(groundSprite->getSprite().value().getPosition());
                Direction spriteDir = getSpriteDirection(stevePos, spritePos);

                if (spriteDir != clickDir) continue;

                if (isSpriteWithinReach(stevePos, spritePos)) {
                    groundSprite->damage(Constants::STEVE_ATTACK_DAMAGE, spriteDir);
                    steve.restartAttackClock();
                }
            }
        }
    }
}

bool EventHandler::isWithinReach(int x, int y, int steveX, int steveY) const {
    return std::abs(steveX - x) <= Constants::STEVE_REACH_DISTANCE && std::abs(steveY - y) <= Constants::STEVE_REACH_DISTANCE;
}

bool EventHandler::isSpriteWithinReach(sf::Vector2f& stevePos, sf::Vector2f& spritePos) const {
    return abs(stevePos.x - spritePos.x) <= Constants::STEVE_ATTACK_DISTANCE
        && abs(stevePos.y - spritePos.y) <= Constants::STEVE_ATTACK_DISTANCE;
}
