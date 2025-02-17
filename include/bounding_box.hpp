#pragma once
#include "object.hpp"

class BoundingBox: public Object {
public:
    BoundingBox(sf::Vector2f size, sf::Vector2f centerShift={0, 0});

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape boundingBox;
};