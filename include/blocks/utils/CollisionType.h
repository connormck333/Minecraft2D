#ifndef COLLISIONTYPE_H
#define COLLISIONTYPE_H
#include "../../sprites/utils/Direction.h"

class CollisionType {
    bool x = false;
    bool y = false;
    bool top = false;
    Direction direction;

public:
    CollisionType(bool x, bool y, bool top, Direction direction);

    [[nodiscard]] Direction getDirection() const;

    [[nodiscard]] bool collisionX() const;

    [[nodiscard]] bool collisionY() const;

    [[nodiscard]] bool collisionTop() const;
};

#endif //COLLISIONTYPE_H
