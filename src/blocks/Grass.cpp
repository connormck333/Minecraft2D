#include "../../include/blocks/Grass.h"

Grass::Grass() : Block("blocks2.png") {
    loadBlock(0, 64, 63, 63);

    sprite->setPosition(sf::Vector2f(350, 399));
}
