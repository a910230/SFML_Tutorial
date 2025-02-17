#include <iostream>
#include <SFML/Graphics.hpp>
#include "character_and_name.hpp"
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

    CharacterAndName player(warrior, name, mingliu);
    // player.scale({0.75f, 0.75f});
    player.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});

    sf::Texture grassTexture;
    if (!grassTexture.loadFromFile("../../assets/grass.png")) {
        cerr << "Error loading grass texture!" << endl;
        return 1;
    }
    
    Terrain terrain(grassTexture, vector<sf::Vector2f>{{300.f, 800.f}, {800.f, 800.f}, {1300.f, 600.f}, {1600.f, 600.f}});

    sf::Text debug_log(mingliu);
    debug_log.setFillColor(sf::Color::Blue);
    debug_log.setPosition({window.getSize().x - 600, 0});
    debug_log.setString(format("x = {}, y = {}", player.getPosition().x, player.getPosition().y));

    sf::Text mouse_pos(mingliu);
    mouse_pos.setFillColor(sf::Color::Blue);
    mouse_pos.setPosition({0, 0});

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

        mouse_pos.setString(format("x = {}, y = {}", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
        // player.fall();

        window.clear(sf::Color::White);
        window.draw(terrain);
        window.draw(player);
        // window.draw(debug_log);
        // window.draw(mouse_pos);

        window.display();
    }
}
