#pragma once
#include <SFML/Graphics.hpp>
#include "terrain.hpp"
using namespace std;

class Character:
    public sf::Drawable,
    public sf::Transformable {
public:
    Character(const sf::Texture& texture, const sf::Font& font, wstring char_name);
    void moveRight();
    void moveLeft();
    bool isAttachedTo(Terrain& terrain, sf::Text& debug_log);
    void fall(Terrain& terrain, sf::Text& debug_log);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite character;
    sf::Text name;
    sf::CircleShape centerDot;
    sf::RectangleShape boundingBox;
    sf::Vector2f boundingBoxShiftX;
    sf::Vector2f boundingBoxShiftY;
    sf::Vector2f boundingCenter;
    sf::CircleShape boundingCenterDot;
    bool faceRight;

    void flip();
    void defHelperShape();
};