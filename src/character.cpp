#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Character: 
    public sf::Drawable,
    public sf::Transformable {
public:
    Character(const sf::Texture& texture, const sf::Font& font, wstring char_name): character(texture), name(font) {        
        centerDot = sf::CircleShape(5.f);
        centerDot.setFillColor(sf::Color(255, 0, 0, 200));
        centerDot.setOrigin(centerDot.getGeometricCenter());
        
        character.setScale({0.25f, 0.25f});
        sf::Vector2f center = character.getLocalBounds().getCenter();
        center -= {30.f, 0.f};
        character.setOrigin(center);
        centerDot.setPosition(character.getPosition());
   
        // name.setString(char_name);
        // name.setCharacterSize(24);
        // name.setFillColor(sf::Color::Red);
        // name.setOrigin(name.getLocalBounds().getCenter());
        // name.setPosition(center);
        // name.setPosition(center + sf::Vector2f{-300.f, -400.f});

        faceRight = true;
    }

    void moveRight() {
        if (faceRight == false) {
            character.scale({-1.f, 1.f});
            faceRight = true;
        }
        move({1.f, 0.f});
    }
    void moveLeft() {
        if (faceRight) {
            character.scale({-1.f, 1.f});
            faceRight = false;
        }
        move({-1.f, 0.f});
    }

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
        
        target.draw(character, states);  // Draw the character sprite
        target.draw(name, states);       // Draw the name text
        target.draw(centerDot, states);
    }

private:
    sf::Sprite character;
    sf::Text name;
    sf::CircleShape centerDot;
    bool faceRight;
};