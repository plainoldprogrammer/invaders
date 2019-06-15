#include <SFML/Graphics.hpp>
#include "easylogging++.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

INITIALIZE_EASYLOGGINGPP


int main()
{
    LOG(INFO) << "Game start";

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Invaders Clone");

    // Create the player ship texture.
    sf::Texture playerShipTexture;
    playerShipTexture.loadFromFile("textures/player-ship.png");

    // Create the player ship sprite.
    sf::Sprite playerShipSprite;
    playerShipSprite.setTexture(playerShipTexture);
    playerShipSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    playerShipSprite.setPosition(0, 0);

    // Draw the game
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        playerShipSprite.setPosition((WINDOW_WIDTH / 2) - 16, WINDOW_HEIGHT - (32 * 2));
        window.draw(playerShipSprite);
        window.display();
    }

    LOG(INFO) << "Game was closed";

    return 0;
}
