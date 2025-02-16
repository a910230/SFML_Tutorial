#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"
// #include "terrain.hpp"
using namespace std;

class Character:
    public Object {
public:
    Character(const sf::Texture& texture, const sf::Font& font, wstring char_name);
    void moveRight();
    void moveLeft();
    bool isAttachedTo(Terrain& terrain);
    void fall();

private:
    // sf::Sprite character;
    // sf::Text name;
    // sf::CircleShape centerDot;
    // sf::RectangleShape boundingBox;
    // sf::Vector2f boundingBoxShiftX;
    // sf::Vector2f boundingBoxShiftY;
    // sf::Vector2f boundingCenter;
    // sf::CircleShape boundingCenterDot;
    bool faceRight;

    void flip();
    // void defHelperShape();
};