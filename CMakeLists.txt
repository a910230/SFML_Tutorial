cmake_minimum_required(VERSION 3.28)
project(SFML-Game-101)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(game101
    src/main.cpp
    src/object.cpp
    src/children.cpp
    src/character_and_name.cpp
    src/name_tag.cpp
    src/character.cpp
    src/bounding_box.cpp
    src/terrain.cpp
    src/math.cpp
)
target_compile_features(game101 PRIVATE cxx_std_20)
target_link_libraries(game101 PRIVATE SFML::Graphics)