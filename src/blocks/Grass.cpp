#include "../../include/blocks/Grass.h"

Grass::Grass(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(0, 64, 63, 63);
    sprite->setPosition(pos);
}
