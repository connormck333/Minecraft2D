cmake_minimum_required(VERSION 3.28)
project(MinecraftClone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforce the standard
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES main.cpp
        src/sprites/Steve.cpp
        src/sprites/GameSprite.cpp
        src/sprites/GroundSprite.cpp
        src/blocks/grass.cpp
        src/blocks/Block.cpp
        src/blocks/Dirt.cpp
        src/blocks/Stone.cpp
        src/terrain/ValueNoise.cpp
        src/blocks/utils/CollisionType.cpp
        src/utils.cpp
        src/blocks/IronOre.cpp
        src/blocks/DiamondOre.cpp
        src/blocks/GoldOre.cpp
        src/blocks/EmeraldOre.cpp
        src/handlers/EventHandler.cpp
        src/handlers/InputHandler.cpp
        src/terrain/WorldGenerator.cpp
        src/terrain/Tree.cpp
        src/blocks/OakWood.cpp
        src/blocks/Leaves.cpp
        src/inventory/Hotbar.cpp
        src/inventory/items/DirtItem.cpp
        src/inventory/items/Item.cpp
        src/inventory/items/StoneItem.cpp
        src/inventory/items/WoodItem.cpp
        src/inventory/items/DiamondItem.cpp
        src/inventory/items/EmeraldItem.cpp
        src/inventory/items/GoldItem.cpp
        src/inventory/items/IronItem.cpp
        src/sprites/hostiles/Zombie.cpp
        src/handlers/SpriteHandler.cpp
        src/sprites/AutomatedSprite.cpp
        src/sprites/hostiles/Creeper.cpp
        src/inventory/Healthbar.cpp
        src/screens/RespawnScreen.cpp
        src/handlers/RespawnHandler.cpp
        src/screens/CraftScreen.cpp
        src/screens/Screen.cpp
        src/inventory/crafting/CraftItem.cpp
        src/inventory/crafting/WoodPickaxe.cpp
        src/inventory/items/tools/WoodPickaxeItem.cpp
        src/inventory/crafting/StonePickaxe.cpp
        src/inventory/crafting/IronPickaxe.cpp
        src/inventory/items/tools/StonePickaxeItem.cpp
        src/inventory/items/tools/IronPickaxeItem.cpp
        src/inventory/items/tools/PickaxeItem.cpp
        src/inventory/items/swords/SwordItem.cpp
        src/inventory/items/swords/WoodSwordItem.cpp
        src/inventory/crafting/WoodSword.cpp
        src/inventory/crafting/StoneSword.cpp
        src/inventory/crafting/IronSword.cpp
        src/inventory/crafting/GoldSword.cpp
        src/inventory/crafting/DiamondSword.cpp
        src/inventory/items/swords/StoneSwordItem.cpp
        src/inventory/items/swords/IronSwordItem.cpp
        src/inventory/items/swords/GoldSwordItem.cpp
        src/inventory/items/swords/DiamondSwordItem.cpp)
set(CMAKE_PREFIX_PATH "/opt/homebrew")
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})

# Point the SFML_DIR to your local copy of the framework
set(SFML_DIR "/opt/homebrew/Cellar/sfml/3.0.0")
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
include_directories(${SFML_DIR}/include)
link_directories(${SFML_DIR}/lib)
add_definitions(-DSFML_STATIC)

add_executable(MinecraftClone ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window)