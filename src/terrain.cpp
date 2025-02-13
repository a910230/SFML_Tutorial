#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

// Constants
const int TILE_SIZE = 64;
const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 10;
const int WINDOW_WIDTH = MAP_WIDTH * TILE_SIZE;
const int WINDOW_HEIGHT = MAP_HEIGHT * TILE_SIZE;

class Terrain {
public:
    Terrain(): background(backgroundTexture) {
        if (!grassTexture.loadFromFile("../../assets/grass.png")) {
            cerr << "Error loading grass texture!" << endl;
        }
        if (!backgroundTexture.loadFromFile("../../assets/background.png")) {
            cerr << "Error loading background texture!" << endl;
        }

        // background.setTexture(backgroundTexture);
        background.setScale({
            (float)WINDOW_WIDTH / backgroundTexture.getSize().x, 
            (float)WINDOW_HEIGHT / backgroundTexture.getSize().y}
        );

        generateTerrain();
    }

    void generateTerrain() {
        srand(time(0)); // Seed random number generator

        for (int x = 0; x < MAP_WIDTH; ++x) {
            int groundLevel = MAP_HEIGHT - (rand() % 3 + 2); // Vary platform height

            for (int y = groundLevel; y < MAP_HEIGHT; ++y) {
                sf::Sprite tile(grassTexture);
                // tile.setTexture(grassTexture);
                tile.setPosition({x * TILE_SIZE, y * TILE_SIZE});
                tiles.push_back(tile);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        for (auto& tile : tiles) {
            window.draw(tile);
        }
    }

private:
    sf::Texture grassTexture, backgroundTexture;
    sf::Sprite background;
    vector<sf::Sprite> tiles;
};
