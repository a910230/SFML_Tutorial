#include <SFML/Graphics.hpp>
#include "bounding_box.hpp"

BoundingBox::BoundingBox(sf::Vector2f size, sf::Vector2f centerShift) {
    boundingBox = sf::RectangleShape(size);
    boundingBox.setOrigin(boundingBox.getGeometricCenter() + centerShift);
    boundingBox.setFillColor(sf::Color(0, 0, 0, 0));
    boundingBox.setOutlineColor(sf::Color::Red);
    boundingBox.setOutlineThickness(1.f);
}

void BoundingBox::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    Object::draw(target, states);

    states.transform *= getTransform();
    target.draw(boundingBox, states);
}

sf::Vector2f BoundingBox::getSize() const {
    return boundingBox.getSize();
}