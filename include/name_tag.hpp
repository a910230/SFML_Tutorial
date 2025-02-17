#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"
using namespace std;

class NameTag: public Object {
public:
    NameTag(wstring char_name, const sf::Font& font);
private:
    sf::Text name;
};