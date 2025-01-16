#ifndef COLLISIONTYPE_H
#define COLLISIONTYPE_H
#include "../../sprites/utils/Direction.h"

class CollisionType {
    bool x = false;
    bool y = false;
    Direction direction;

public:
    CollisionType(bool x, bool y, Direction direction);

    [[nodiscard]] Direction getDirection() const;

    [[nodiscard]] bool collisionX() const;

    [[nodiscard]] bool collisionY() const;
};

#endif //COLLISIONTYPE_H
