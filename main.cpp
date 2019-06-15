#include "easylogging++.h"
#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
#include "EnemyShip.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

INITIALIZE_EASYLOGGINGPP


int main()
{
    LOG(INFO) << "Game start";

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Invaders Clone");

    // Create the player ship sprite.
    PlayerShip *playerShip = new PlayerShip();

    // Create an enemy ship sprite.
    EnemyShip *enemyShip = new EnemyShip();

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
        playerShip->setPosition((WINDOW_WIDTH / 2) - 16, WINDOW_HEIGHT - (32 * 2));
        enemyShip->setPosition(32, 32);
        window.draw(*playerShip);
        window.draw(*enemyShip);
        window.display();
    }

    LOG(INFO) << "Game was closed";

    return 0;
}
