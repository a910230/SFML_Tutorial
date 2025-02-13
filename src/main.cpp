#include <SFML/Graphics.hpp>
#include "character.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Game-101");
    window.setFramerateLimit(144);

    // sf::Texture warrior("../../assets/character0.png");
    // sf::Sprite warrior1(warrior);
    // warrior1.setScale({0.25f, 0.25f});
    // warrior1.setOrigin({warrior.getSize().x * 0.5f, warrior.getSize().y * 0.5f});
    // warrior1.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});
    // warrior1.scale({-1.f, 1.f});
    Character player;
    player.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});

    // sf::Font mingliu("../../assets/mingliu.ttc");
    // sf::Text name(mingliu);
    // name.setString(L"你的名字");
    // name.setCharacterSize(24);
    // name.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
                warrior1.move({1.f, 0.f});
            }
        }

        window.clear(sf::Color::White);
        window.draw(warrior1);
        window.draw(name);
        window.display();
    }
}
