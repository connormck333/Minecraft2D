#include "../../include/blocks/Leaves.h"

Leaves::Leaves(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 0);
    sprite->setPosition(pos);
}
