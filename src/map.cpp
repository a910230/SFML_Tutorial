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
        
size_t Map::appendCharacter(Character* character, string name) {
    return characters.append(character, name);
}
        
bool Map::removeCharacter(string name) {
    return characters.remove(name);
}
        
bool Map::removeCharacter(size_t id) {
    return characters.remove(id);
}