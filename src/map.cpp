#include "map.hpp"

Map::Map() {}
        
size_t Map::appendTerrain(Terrain* terrain, string name) {
    return terrains.append(terrain, name);
}
        
bool Map::removeTerrain(string name) {
    return terrains.remove(name);
}
        
bool Map::removeTerrain(size_t id) {
    return terrains.remove(id);
}
        
size_t Map::appendCharacter(CharacterAndName* character, string name) {
    return characters.append(character, name);
}
        
bool Map::removeCharacter(string name) {
    return characters.remove(name);
}
        
bool Map::removeCharacter(size_t id) {
    return characters.remove(id);
}

bool Map::isOnTerrain(sf::Vector2f position) {
    for (auto& pair: terrains) {
        if (dynamic_cast<Terrain*>(pair.second)->isOn(position)) {
            return true;
        }
    }
    return false;
}

Terrain* Map::getTerrain(sf::Vector2f position) {
    for (auto& pair: terrains) {
        if (dynamic_cast<Terrain*>(pair.second)->isOn(position)) {
            return dynamic_cast<Terrain*>(pair.second);
        }
    }
    return nullptr;
}

Children Map::getCharacters() {
    return characters;
}

Children Map::getTerrains() {
    return terrains;
}