#include "../../../include/blocks/utils/CollisionType.h"

CollisionType::CollisionType(bool x, bool y, bool top, Direction dir) {
    this->x = x;
    this->y = y;
    this->top = top;
    this->direction = dir;
}

bool CollisionType::collisionX() const {
    return x;
}

bool CollisionType::collisionY() const {
    return y;
}

bool CollisionType::collisionTop() const {
    return top;
}

Direction CollisionType::getDirection() const {
    return direction;
}

