#include "name_tag.hpp"

NameTag::NameTag(wstring char_name, const sf::Font& font):name(font) {
    name.setString(char_name);
    name.setCharacterSize(24);
    name.setFillColor(sf::Color::Red);
}


// name.setOrigin(name.getLocalBounds().getCenter());
// name.setPosition(character.getPosition() + sf::Vector2f{0.f, 120.f});