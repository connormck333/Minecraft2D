#include "../../include/blocks/GoldOre.h"

GoldOre::GoldOre(sf::Vector2f pos) : Block("blocks2.png") {
    loadBlock(128, 128);
    sprite->setPosition(pos);
}
