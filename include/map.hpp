#pragma once
#include "character.hpp"
#include "terrain.hpp"
#include "children.hpp"

class Map {
public:
    Map();
    size_t appendTerrain(Terrain* terrain, string name);
    bool removeTerrain(string name);
    bool removeTerrain(size_t id);
    size_t appendCharacter(Character* character, string name);
    bool removeCharacter(string name);
    bool removeCharacter(size_t id);

private:
    Children characters;
    Children terrains;
};