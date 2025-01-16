#include "../../../include/blocks/utils/CollisionType.h"

CollisionType::CollisionType(bool x, bool y, Direction dir) {
    this->x = x;
    this->y = y;
    this->direction = dir;
}

bool CollisionType::collisionX() const {
    return x;
}

bool CollisionType::collisionY() const {
    return y;
}

Direction CollisionType::getDirection() const {
    return direction;
}

