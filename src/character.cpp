#include <iostream>
#include <SFML/Graphics.hpp>
#include "character.hpp"
// #include "terrain.hpp"
using namespace std;

Character::Character(const sf::Texture& texture, const sf::Font& font, wstring char_name): character(texture), name(font) {
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

void Character::moveRight() {
    if (!faceRight) {
        flip();
    }
    else {
        move({1.f, 0.f});
    }
}
void Character::moveLeft() {
    if (faceRight) {
        flip();
    }
    else {
        move({-1.f, 0.f});
    }
}

bool Character::isAttachedTo(Terrain& terrain, sf::Text& debug_log) {
    return terrain.isOn(boundingCenter, debug_log);
}

void Character::fall(Terrain& terrain, sf::Text& debug_log) { // Should be modified to take Map as input
    if (!isAttachedTo(terrain, debug_log)) {
        move({0.f, 1.f});
    }
    // TODO: Move the character to exactly attach to the terrain
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
    
    target.draw(character, states);  // Draw the character sprite
    target.draw(name, states);       // Draw the name text
    // target.draw(centerDot, states);
    target.draw(boundingBox, states);
    target.draw(boundingCenterDot, states);
}

void Character::flip() {
    character.scale({-1.f, 1.f});
    if (faceRight) {
        boundingBox.setPosition(character.getPosition() - boundingBoxShiftX + boundingBoxShiftY);
    }
    else {
        boundingBox.setPosition(character.getPosition() + boundingBoxShiftX + boundingBoxShiftY);
    }
    faceRight = !faceRight;
}

void Character::defHelperShape() {
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

    boundingCenter = sf::Vector2f({centerDot.getPosition().x, boundingBox.getPosition().y + boundingBox.getSize().y / 2});
    boundingCenterDot = sf::CircleShape(5.f);
    boundingCenterDot.setFillColor(sf::Color(0, 0, 255, 200));
    boundingCenterDot.setOrigin(centerDot.getGeometricCenter());
    boundingCenterDot.setPosition(boundingCenter);
}