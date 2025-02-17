#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Object:
    public sf::Drawable,
    public sf::Transformable {
public:
    Object();
    bool appendChild(Object* child, string name);
    bool removeChild(string name);
    Object* getChild(string name);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    unordered_map<string, Object*> children;
};