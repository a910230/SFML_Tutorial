#include <iostream>
#include <SFML/Graphics.hpp>
#include "character.hpp"
#include "terrain.hpp"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Game-101");
    window.setFramerateLimit(144);
    
    sf::Texture warrior;
    if (!warrior.loadFromFile("../../assets/character0.png")) {
        cerr << "Error loading warrior texture!" << endl;
        return 1;
    }
    sf::Font mingliu("../../assets/mingliu.ttc");
    wstring name = L"哆哆哆大王";

    Character player(warrior, mingliu, name);
    player.scale({0.75f, 0.75f});
    player.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});

    sf::Texture grassTexture;
    if (!grassTexture.loadFromFile("../../assets/grass.png")) {
        cerr << "Error loading grass texture!" << endl;
        return 1;
    }
    
    Terrain terrain(grassTexture, vector<sf::Vector2f>{{300.f, 800.f}, {800.f, 800.f}, {1300.f, 600.f}, {1600.f, 600.f}});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                player.moveRight();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
                player.moveLeft();
            }
        }

        player.fall(terrain);

        window.clear(sf::Color::White);
        window.draw(terrain);
        window.draw(player);

        window.display();
    }
}
