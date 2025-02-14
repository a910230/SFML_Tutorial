#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Terrain:
    public sf::Drawable,
    public sf::Transformable {
public:
    Terrain(const sf::Texture& texture): terrain(texture) {
    }

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
        
        target.draw(terrain, states);
        // target.draw(boundingBox, states);
    }

private:
    sf::Sprite terrain;
};
