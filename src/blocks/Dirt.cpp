#include "../../include/blocks/Dirt.h"

Dirt::Dirt(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 128);
    sprite->setPosition(pos);
}
