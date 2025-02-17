#include "object.hpp"

Object::Object() {}

bool Object::appendChild(Object* child, string name) {
    return children.insert(make_pair(name, child)).second;
}

bool Object::removeChild(string name) {
    return children.erase(name);
}

Object* Object::getChild(string name) {
    return children[name];
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();  // Apply transformations from the parent (position, scale, rotation)
    for (const auto& [key, child]: children) {
        target.draw(*child, states);
    }
}