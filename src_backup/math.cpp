#include <SFML/Graphics.hpp>
#include "math.hpp"

sf::Vector2f interpolate(sf::Vector2f begin, sf::Vector2f end, float x) {
    float y = begin.y + (x - begin.x) / (end.x - begin.x) * (end.y - begin.y);
    return sf::Vector2f({x, y});
}