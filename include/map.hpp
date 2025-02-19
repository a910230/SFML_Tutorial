#pragma once
#include "character_and_name.hpp"
#include "terrain.hpp"
#include "children.hpp"

class Map {
public:
    Map();
    size_t appendTerrain(Terrain* terrain, string name);
    bool removeTerrain(string name);
    bool removeTerrain(size_t id);
    size_t appendCharacter(CharacterAndName* character, string name);
    bool removeCharacter(string name);
    bool removeCharacter(size_t id);
    bool isOnTerrain(sf::Vector2f position);
    Terrain* getTerrain(sf::Vector2f position);
    Children getCharacters();
    Children getTerrains();

private:
    Children characters;
    Children terrains;
};