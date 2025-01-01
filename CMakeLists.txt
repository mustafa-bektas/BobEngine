cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Add the include directory to the search paths
include_directories(${CMAKE_SOURCE_DIR}/include/core)

add_executable(main src/main.cpp
        src/core/GameLoop.cpp
        src/core/InputHandler.cpp
        src/core/Game.cpp
        include/core/Game.hpp
        include/core/GameLoop.hpp
        include/core/InputHandler.hpp
        src/core/ShapeFactory.cpp
        include/core/ShapeFactory.hpp
)
target_link_libraries(main PRIVATE SFML::Graphics)
