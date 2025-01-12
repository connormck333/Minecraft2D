#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include "../sprites/GroundSprite.h"

class Block : public GameSprite {
public:
    explicit Block(const std::string& fileName);

    void loadBlock(int x, int y, int height, int width);

    bool collidesWith(GroundSprite* sprite) const;
};

#endif //BLOCK_H
