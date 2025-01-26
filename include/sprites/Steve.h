#ifndef STEVE_H
#pragma once

#define STEVE_H

#include "GroundSprite.h"

class Steve final : public GroundSprite {
private:
    sf::Clock attackClock;
    void createTextures();

public:
    explicit Steve(sf::Vector2f pos);

    void handleEvent(sf::Event ev);

    void respawn(sf::Vector2f spawnPos);

    [[nodiscard]] bool canAttack() const;
    void restartAttackClock();
};

#endif //STEVE_H
