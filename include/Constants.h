#pragma once
namespace Constants {
    constexpr int SCREEN_HEIGHT = 800;
    constexpr int SCREEN_WIDTH = 600;

    constexpr int BLOCK_SIZE = 63;
    constexpr int WORLD_HEIGHT = 100;
    constexpr int WORLD_WIDTH = 100;

    constexpr int TREES_AMOUNT = 3;

    constexpr float STEVE_MOVEMENT_SPEED = 0.09f;

    constexpr int HOTBAR_HEIGHT = 51;
    constexpr int HOTBAR_WIDTH = 389;
    constexpr sf::Vector2i HOTBAR_POSITION = sf::Vector2i(
        (SCREEN_WIDTH - (HOTBAR_WIDTH / 2)) / 2,
        SCREEN_HEIGHT - HOTBAR_HEIGHT - 210
    );
}
