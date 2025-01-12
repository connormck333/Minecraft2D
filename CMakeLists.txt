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
        include/sprites/utils/Direction.h
        include/blocks/Dirt.h
        src/blocks/Dirt.cpp
        include/blocks/Stone.h
        src/blocks/Stone.cpp)
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