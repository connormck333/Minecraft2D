#pragma once
namespace Constants {
    constexpr int SCREEN_HEIGHT = 800;
    constexpr int SCREEN_WIDTH = 600;

    constexpr int BLOCK_SIZE = 63;
    constexpr int WORLD_HEIGHT = 100;
    constexpr int WORLD_WIDTH = 100;

    constexpr int TREES_AMOUNT = WORLD_WIDTH / 10;

    constexpr int STEVE_REACH_DISTANCE = 3;

    constexpr float STEVE_MOVEMENT_SPEED = 0.13f;
    constexpr float HOSTILE_MOVEMENT_SPEED = 0.08f;

    constexpr int STEVE_HEALTH = 5;
    constexpr int STEVE_DAMAGE = 1;
    constexpr int RESPAWN_TIME = 3;

    constexpr int MAX_MOB_AMOUNT = 10;
    constexpr int MOB_SPAWN_RATE_SECONDS = 10;
    constexpr int ZOMBIE_HEALTH = 5;
    constexpr int CREEPER_HEALTH = 3;

    constexpr int HOTBAR_HEIGHT = 51;
    constexpr int HOTBAR_WIDTH = 389;
    constexpr sf::Vector2i HOTBAR_POSITION = sf::Vector2i(
        (SCREEN_WIDTH - (HOTBAR_WIDTH / 2)) / 2,
        SCREEN_HEIGHT - HOTBAR_HEIGHT - 210
    );

    constexpr int HOTBAR_SLOT_YPOS = 11;
    inline std::unordered_map<int, int> HOTBAR_SLOT_XPOS = {
        {0, 10},
        {1, 59},
        {2, 107},
        {3, 154},
        {4, 202},
        {5, 250},
        {6, 298},
        {7, 346}
    };
    constexpr int HOTBAR_SLOT_SIZE = 27;
    constexpr int HOTBAR_SLOT_GAP = 15;
    constexpr int HOTBAR_LEFT_PADDING = 10;
}
