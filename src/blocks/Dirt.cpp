#include "../../include/blocks/Dirt.h"

Dirt::Dirt() : Block("blocks2.png") {
    loadBlock(0, 128, 63, 63);

    sprite->setPosition(sf::Vector2f(350, 399 + 63));
}
