#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../sprites/Steve.h"

class InputHandler {
private:
  Steve& steve;

public:
    InputHandler(Steve& steve);

    void handle() const;
};

#endif //INPUTHANDLER_H
