#include "../../include/blocks/DiamondOre.h"

DiamondOre::DiamondOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(64, 64);
    sprite->setPosition(pos);
}
