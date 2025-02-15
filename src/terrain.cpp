#include <iostream>
#include <SFML/Graphics.hpp>
#include "math.hpp"
#include "terrain.hpp"
using namespace std;

Terrain::Terrain(const sf::Texture& terrain_texture): texture(terrain_texture) {}

Terrain::Terrain(const sf::Texture& terrain_texture, vector<sf::Vector2f> corners): texture(terrain_texture) {
    bounding = sf::VertexArray(sf::PrimitiveType::LineStrip, corners.size());
    for (int i = 0; i < corners.size(); ++i) {
        bounding[i].position = corners[i];
        bounding[i].color = sf::Color::Red;
    }

    texture.setRepeated(true);
    for (int i = 0; i < corners.size() - 1; ++i) {
        sf::Sprite t(texture);
        sf::Vector2f line = corners[i + 1] - corners[i];
        t.setTextureRect(sf::IntRect({0, 0}, {(int)line.length(), (int)texture.getSize().y}));
        t.setOrigin({0, 45.f});
        t.setPosition(corners[i]);
        t.setRotation(line.angle());
        terrain.push_back(t);
    }
}

bool Terrain::isOn(sf::Vector2f v) {
    int i = 0;
    while (bounding[i].position.x < v.x) {
        ++i;
    }
    if (i == 0) return false;
    sf::Vector2f boundingPoint = interpolate(bounding[i - 1].position, bounding[i].position, v.x);
    return (abs(v.y - boundingPoint.y) <= 1.f);
}

void Terrain::fillBottom(sf::RenderWindow& window) {}

void Terrain::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
    
    for (auto& t: terrain) {
        target.draw(t, states);
    }
    target.draw(bounding, states);
}
