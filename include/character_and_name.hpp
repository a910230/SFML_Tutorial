#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"
#include "terrain.hpp"
// #include "map.hpp"
using namespace std;

class Map;

class CharacterAndName:
    public Object {
public:
    CharacterAndName(Map& map, const sf::Texture& texture, wstring char_name, const sf::Font& font);
    void moveRight();
    void moveLeft();
    // bool isAttachedTo(Terrain& terrain);
    bool isAttachedToTerrain();
    void fall();
    sf::Vector2f getAttachingPosition();

private:
    // sf::Sprite character;
    // sf::Text name;
    // sf::CircleShape centerDot;
    // sf::Vector2f boundingBoxShiftX;
    // sf::Vector2f boundingBoxShiftY;
    // sf::Vector2f boundingCenter;
    bool faceRight;
    Map& map;
    Terrain* attachedTerrain;
    void attachToTerrain();

    // void flip();
    // void defHelperShape();
};