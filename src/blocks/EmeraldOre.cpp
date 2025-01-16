#include "../../include/blocks/EmeraldOre.h"

EmeraldOre::EmeraldOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(64, 128);
    sprite->setPosition(pos);
}
