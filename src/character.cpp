#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Character: public sf::Sprite {
public:
    Character() {
        if (!warrior.loadFromFile("../../assets/character0.png")) {
            cerr << "Error loading warrior texture!" << endl;
        }
        else setTexture(warrior);
        
        setScale({0.25f, 0.25f});
        setOrigin({warrior.getSize().x * 0.5f, warrior.getSize().y * 0.5f});
        scale({-1.f, 1.f});
    }

    // sf::Font mingliu("../../assets/mingliu.ttc");
    // sf::Text name(mingliu);
    // name.setString(L"你的名字");
    // name.setCharacterSize(24);
    // name.setFillColor(sf::Color::Red);

private:
    sf::Texture warrior;
};