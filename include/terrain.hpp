#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Terrain:
    public sf::Drawable,
    public sf::Transformable {
public:
    Terrain();
    Terrain(const sf::Texture& terrain_texture);
    Terrain(const sf::Texture& terrain_texture, vector<sf::Vector2f> corners);
    bool isOn(sf::Vector2f v, sf::Text& debug_log);
protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::VertexArray bounding;
    sf::Texture texture;
    vector<sf::Sprite> terrain;
};
