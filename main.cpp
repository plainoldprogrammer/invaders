#include "easylogging++.h"
#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Bullet.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

INITIALIZE_EASYLOGGINGPP

bool isPlayerShipInOriginalPosition = true;
bool isBulletFired = false;


int main()
{
	LOG(INFO) << "Game start";

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Invaders Clone");

	// Create the player ship sprite.
	PlayerShip *playerShip = new PlayerShip();

	// Create an enemy ship sprite.
	EnemyShip *enemyShip = new EnemyShip();

	// Create a single bullet.
	Bullet *bullet = new Bullet();


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
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					LOG(INFO) << "Left arrow key was pressed";
					playerShip->moveLeft();
					isPlayerShipInOriginalPosition = false;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					LOG(INFO) << "Right arrow key was pressed";
					playerShip->moveRight();
					isPlayerShipInOriginalPosition = false;
				}
				else if (event.key.code == sf::Keyboard::Space)
				{
					LOG(INFO) << "Shoot a bullet";
					isBulletFired = true;
					bullet->playSound();
				}
			}
		}

		window.clear();

		if (isPlayerShipInOriginalPosition)
		{
			playerShip->setPosition((WINDOW_WIDTH / 2) - 16, WINDOW_HEIGHT - (32 * 2));
		}
		else
		{
			playerShip->setPosition(playerShip->getPosition().x, playerShip->getPosition().y);
		}

		enemyShip->setPosition(32, 32);

		if (isBulletFired)
		{
			bullet->setPosition(playerShip->getPosition().x + ( (playerShip->getTexture()->getSize().x / 2) - (bullet->getTexture()->getSize().x / 2) ), bullet->getPosition().y - .08);
		}
		else
		{
			bullet->setPosition(playerShip->getPosition().x + ( (playerShip->getTexture()->getSize().x / 2) - (bullet->getTexture()->getSize().x / 2) ), playerShip->getPosition().y - (bullet->getTexture()->getSize().y * 3));
		}

		window.draw(*playerShip);
		window.draw(*enemyShip);
		window.draw(*bullet);
		window.display();
	}

	LOG(INFO) << "Game was closed";

	return 0;
}
