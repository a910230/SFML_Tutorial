#include <iostream>
#include <SFML/Graphics.hpp>
#include "character_and_name.hpp"
#include "name_tag.hpp"
#include "character.hpp"
#include "bounding_box.hpp"
#include "map.hpp"
#include "attaching_pivot.hpp"
using namespace std;

CharacterAndName::CharacterAndName(Map& map, const sf::Texture& texture, wstring char_name, const sf::Font& font): map(map), attachedTerrain(nullptr) {
    faceRight = true;
    appendChild(new NameTag(char_name, font), "nameTag");
    appendChild(new Character(texture), "character");
    appendChild(new BoundingBox({105.f, 153.5f}, {0.f, -24.f}), "boundingBox");
    // Calculate the position for the AttachingPivot
    BoundingBox* boundingBox = dynamic_cast<BoundingBox*>(getChild("boundingBox"));
    sf::Vector2f attachingPivotPosition = {0.f, 24.f + boundingBox->getSize().y / 2};
    appendChild(new AttachingPivot(attachingPivotPosition), "attachingPivot");
}

void CharacterAndName::moveRight() {
    if (!faceRight) {
        faceRight = true;
        dynamic_cast<Character*>(getChild("character"))->flip();
    }
    else {
        move({1.f, 0.f});
    }
}
void CharacterAndName::moveLeft() {
    if (faceRight) {
        faceRight = false;
        dynamic_cast<Character*>(getChild("character"))->flip();
    }
    else {
        move({-1.f, 0.f});
    }
}

// bool CharacterAndName::isAttachedTo(Terrain& terrain) {
//     return terrain.isOn(getPosition() + boundingCenterDot.getPosition(), debug_log);
// }

bool CharacterAndName::isAttachedToTerrain() {
    return (attachedTerrain != nullptr);
}

void CharacterAndName::fall() {
    if (!isAttachedToTerrain()) {
        move({0.f, 1.f});
        attachToTerrain();
    }
}

void CharacterAndName::attachToTerrain() {
    // Check if the character is touching any terrain in the map
    if (map.isOnTerrain(getAttachingPosition())) {
        // Move the character to exactly attach to the terrain
        attachedTerrain = map.getTerrain(getAttachingPosition());
        setPosition(attachedTerrain->getOnTerrainPosition(getAttachingPosition()) - dynamic_cast<AttachingPivot*>(getChild("attachingPivot"))->getPosition());
    }
}

sf::Vector2f CharacterAndName::getAttachingPosition() {
    cout << "getPosition() = " << getPosition().x << ", " << getPosition().y << endl;
    cout << "attachingPivot->getPosition() = " << dynamic_cast<AttachingPivot*>(getChild("attachingPivot"))->getPosition().x << ", " << dynamic_cast<AttachingPivot*>(getChild("attachingPivot"))->getPosition().y << endl;
    return getPosition() + dynamic_cast<AttachingPivot*>(getChild("attachingPivot"))->getPosition();
}

// void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const {
//     states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
    
//     target.draw(character, states);  // Draw the character sprite
//     target.draw(name, states);       // Draw the name text
//     // target.draw(centerDot, states);
//     target.draw(boundingBox, states);
//     target.draw(boundingCenterDot, states);
// }

// void Character::defHelperShape() {
//     centerDot = sf::CircleShape(5.f);
//     centerDot.setFillColor(sf::Color(255, 0, 0, 200));
//     centerDot.setOrigin(centerDot.getGeometricCenter());
//     centerDot.setPosition(character.getPosition());
    
//     boundingBoxShiftX = sf::Vector2f{-4.5f, 0.f};
//     boundingBoxShiftY = sf::Vector2f{0.f, 24.f};

//     boundingBox = sf::RectangleShape(character.getGlobalBounds().size - sf::Vector2f{80.f, 60.f});
//     boundingBox.setOrigin(boundingBox.getGeometricCenter());
//     boundingBox.setPosition(character.getPosition() + boundingBoxShiftX + boundingBoxShiftY);
//     boundingBox.setFillColor(sf::Color(0, 0, 0, 0));
//     boundingBox.setOutlineColor(sf::Color(255, 0, 0));
//     boundingBox.setOutlineThickness(2.f);

//     boundingCenter = sf::Vector2f({centerDot.getPosition().x, boundingBox.getPosition().y + boundingBox.getSize().y / 2});
//     boundingCenterDot = sf::CircleShape(5.f);
//     boundingCenterDot.setFillColor(sf::Color(0, 0, 255, 200));
//     boundingCenterDot.setOrigin(centerDot.getGeometricCenter());
//     boundingCenterDot.setPosition(boundingCenter);
// }