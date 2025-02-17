#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"
using namespace std;

class Character: public Object {
public:
    Character(const sf::Texture& texture);
    void flip();

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite character;
};