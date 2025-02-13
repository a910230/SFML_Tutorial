#include <SFML/Graphics.hpp>
#include "character.cpp"

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
    wstring name = L"你的名字";

    Character player(warrior, mingliu, name);
    player.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});

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
        // window.draw(name);
        window.display();
    }
}
