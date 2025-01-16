#include "../../include/blocks/IronOre.h"

IronOre::IronOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(192, 128);
    sprite->setPosition(pos);
}
