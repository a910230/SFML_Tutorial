#include "character.hpp"

Character::Character(const sf::Texture& texture):character(texture) {
    character.setScale({0.25f, 0.25f});
    // sf::Vector2f center = character.getLocalBounds().getCenter();
    // center -= {68.f, 0.f};
    // character.setOrigin(center);

    // defHelperShape();

    
}

void Character::flip() {

}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Object::draw(target, states);

    states.transform *= getTransform();
    target.draw(character, states);
}

// void CharacterAndName::flip() {
//     Character& character = static_cast<Character&>(getChild("character"));
//     character.scale({-1.f, 1.f});
//     if (faceRight) {
//         boundingBox.setPosition(character.getPosition() - boundingBoxShiftX + boundingBoxShiftY);
//     }
//     else {
//         boundingBox.setPosition(character.getPosition() + boundingBoxShiftX + boundingBoxShiftY);
//     }
//     faceRight = !faceRight;
// }