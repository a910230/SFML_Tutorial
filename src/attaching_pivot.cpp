#include "attaching_pivot.hpp"

AttachingPivot::AttachingPivot(sf::Vector2f center) {
    setPosition(center);
    attachingPivot.setRadius(5.f);
    attachingPivot.setOrigin(attachingPivot.getGeometricCenter());
    attachingPivot.setFillColor(sf::Color::Blue);
}

void AttachingPivot::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(attachingPivot, states);
}