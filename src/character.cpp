#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Character:
    public sf::Drawable,
    public sf::Transformable {
public:
    Character(const sf::Texture& texture, const sf::Font& font, wstring char_name): character(texture), name(font) {
        character.setScale({0.25f, 0.25f});
        sf::Vector2f center = character.getLocalBounds().getCenter();
        center -= {68.f, 0.f};
        character.setOrigin(center);

        defHelperShape();
   
        name.setString(char_name);
        name.setCharacterSize(24);
        name.setFillColor(sf::Color::Red);
        name.setOrigin(name.getLocalBounds().getCenter());
        name.setPosition(character.getPosition() + sf::Vector2f{0.f, 120.f});

        faceRight = true;
    }

    void moveRight() {
        if (!faceRight) {
            flip();
        }
        else {
            move({1.f, 0.f});
        }
    }
    void moveLeft() {
        if (faceRight) {
            flip();
        }
        else {
            move({-1.f, 0.f});
        }
    }

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
        
        target.draw(character, states);  // Draw the character sprite
        target.draw(name, states);       // Draw the name text
        // target.draw(centerDot, states);
        target.draw(boundingBox, states);
    }

private:
    sf::Sprite character;
    sf::Text name;
    sf::CircleShape centerDot;
    sf::RectangleShape boundingBox;
    sf::Vector2f boundingBoxShiftX;
    sf::Vector2f boundingBoxShiftY;
    bool faceRight;

    void flip() {
        character.scale({-1.f, 1.f});
        if (faceRight) {
            boundingBox.setPosition(character.getPosition() - boundingBoxShiftX + boundingBoxShiftY);
        }
        else {
            boundingBox.setPosition(character.getPosition() + boundingBoxShiftX + boundingBoxShiftY);
        }
        faceRight = !faceRight;
    }

    void defHelperShape() {
        centerDot = sf::CircleShape(5.f);
        centerDot.setFillColor(sf::Color(255, 0, 0, 200));
        centerDot.setOrigin(centerDot.getGeometricCenter());
        centerDot.setPosition(character.getPosition());
        
        boundingBoxShiftX = sf::Vector2f{-4.5f, 0.f};
        boundingBoxShiftY = sf::Vector2f{0.f, 24.f};

        boundingBox = sf::RectangleShape(character.getGlobalBounds().size - sf::Vector2f{80.f, 60.f});
        boundingBox.setOrigin(boundingBox.getGeometricCenter());
        boundingBox.setPosition(character.getPosition() + boundingBoxShiftX + boundingBoxShiftY);
        boundingBox.setFillColor(sf::Color(0, 0, 0, 0));
        boundingBox.setOutlineColor(sf::Color(255, 0, 0));
        boundingBox.setOutlineThickness(2.f);
    }
};