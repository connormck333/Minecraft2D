#include "../../include/blocks/Stone.h"

Stone::Stone() : Block("blocks2.png") {
    loadBlock(128, 64, 63, 63);

    sprite->setPosition(sf::Vector2f(350, 399 + (63 * 2)));
}
