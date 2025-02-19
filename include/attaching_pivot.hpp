#pragma once
#include "object.hpp"

class AttachingPivot: public Object {
public:
    AttachingPivot(sf::Vector2f center);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::CircleShape attachingPivot;
};