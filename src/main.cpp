#include <SFML/Graphics.hpp>
#include "character.cpp"
#include "terrain.cpp"

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
    if (!grassTexture.loadFromFile("../../assets/useful.png")) {
        cerr << "Error loading grass texture!" << endl;
        return 1;
    }

    Terrain terrain(grassTexture);

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

        window.clear(sf::Color::White);
        window.draw(player);
        window.draw(terrain);

        window.display();
    }
}
