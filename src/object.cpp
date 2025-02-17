#include "object.hpp"

Object::Object() {}

bool Object::appendChild(Object* child, string name) {
    return children.append(child, name);
}

bool Object::removeChild(string name) {
    return children.remove(name);
}

Object* Object::getChild(string name) {
    return children[name];
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
    for (int i = 0; i < children.size(); ++i) {
        target.draw(*(children[i]), states);
    }
}