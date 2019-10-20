#include "easylogging++.h"
#include <SFML/Graphics.hpp>
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Bullet.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define BULLET_VELOCITY 0.5
#define BULLET_LIMIT 1000

INITIALIZE_EASYLOGGINGPP

bool isPlayerShipInOriginalPosition = true;
bool isBulletFired = false;


int main()
{
	LOG(INFO) << "Game start";

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Invaders Clone");

	// Create the player ship sprite.
	PlayerShip *playerShip = new PlayerShip();

	// Create the enemies.
	EnemyShip *enemyShipArray[10];
	for (int i = 0; i < 10; i++)
	{
		enemyShipArray[i] = new EnemyShip();
	}

	// Create a single bullet.
	Bullet *bullet = NULL;

	Bullet *bulletArray[BULLET_LIMIT];
	for (int i = 0; i < BULLET_LIMIT; i++)
	{
		bulletArray[i] = NULL;
	}

	int bulletsCount = 0;
	int destroyedEnemies = 0;

	sf::Text scoreLabel;
	sf::Font standardFont;
	standardFont.loadFromFile("arial.ttf");
	scoreLabel.setFont(standardFont);
	scoreLabel.setString("Score: " + std::to_string(destroyedEnemies));
	scoreLabel.setCharacterSize(12);
	scoreLabel.setFillColor(sf::Color::White);
	scoreLabel.setStyle(sf::Text::Bold);
	scoreLabel.setPosition(10, 6);

	sf::Text gameFinishedLabel;
	gameFinishedLabel.setFont(standardFont);
	gameFinishedLabel.setString("You Win!");
	gameFinishedLabel.setCharacterSize(40);
	gameFinishedLabel.setFillColor(sf::Color::White);
	gameFinishedLabel.setStyle(sf::Text::Bold);
	gameFinishedLabel.setPosition(240, 240);

	bool gameWon = false;

	// Draw the game
	while (window.isOpen())
	{
		// Clean the window every cycle in the game loop.
		window.clear();

		if (isPlayerShipInOriginalPosition)
		{
			playerShip->setPosition((WINDOW_WIDTH / 2) - 16, WINDOW_HEIGHT - (32 * 2));
		}
		else
		{
			playerShip->setPosition(playerShip->getPosition().x, playerShip->getPosition().y);
		}

		// Positioning the enemies in the screen.
		for (int i = 0; i < 10; i++)
		{
			enemyShipArray[i]->setPosition(56 * (i + 1), 32);
		}

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
					isPlayerShipInOriginalPosition = false;		;
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
					bullet = new Bullet(bulletsCount);
					bullet->setPosition(playerShip->getPosition().x + ( (playerShip->getTexture()->getSize().x / 2) - (bullet->getTexture()->getSize().x / 2) ), playerShip->getPosition().y - (bullet->getTexture()->getSize().y * 3));
					bulletArray[bulletsCount] = bullet;
					bulletsCount++;
					bullet->playSound();
				}
			}
		}

		window.draw(*playerShip);

		for (int i = 0; i < 10; i++)
		{
			if (enemyShipArray[i]->shouldBeDrawed)
			{
				window.draw(*enemyShipArray[i]);
			}
		}

		if (bulletsCount > 0)
		{
			// LOG(INFO) << "Draw bullets";
			// LOG(INFO) << "bulletsCount: " << bulletsCount;

			for (int i = 0; i < bulletsCount; i++)
			{
				if (bulletArray[i]->shouldBeDrawed)
				{
					bulletArray[i]->setPosition(bulletArray[i]->getPosition().x, bulletArray[i]->getPosition().y - BULLET_VELOCITY);
					window.draw(*bulletArray[i]);

					// If a bullet impacts with an EnemyShip.
					for (int j = 0; j < 10; j++)
					{
						if (round(bulletArray[i]->getPosition().y) == round(enemyShipArray[j]->getPosition().y + enemyShipArray[j]->getTextureRect().height) &&
							bulletArray[i]->getPosition().x + bulletArray[i]->getTextureRect().width >= enemyShipArray[j]->getPosition().x &&
							bulletArray[i]->getPosition().x <= enemyShipArray[j]->getPosition().x + enemyShipArray[j]->getTextureRect().width &&
							enemyShipArray[j]->shouldBeDrawed)
						{
							LOG(INFO) << "There is a collision on " << round(bulletArray[i]->getPosition().y);
							enemyShipArray[j]->playSound();
							enemyShipArray[j]->shouldBeDrawed = false;
							bulletArray[i]->shouldBeDrawed = false;
							destroyedEnemies++;

							// Check if all enemies was destroyed
							if (destroyedEnemies == 10)
							{
								gameWon = true;
							}
						}
					}
				}
			}
		}

		scoreLabel.setString("Score: " + std::to_string(destroyedEnemies));
		window.draw(scoreLabel);

		if (gameWon)
		{
			window.draw(gameFinishedLabel);
		}

		window.display();
	}

	LOG(INFO) << "Liberating memory";

	for (int i = 0; i < bulletsCount; i++)
	{
		delete bulletArray[i];
	}

	delete bullet;

	for (int i = 0; i < 10; i++)
	{
		delete enemyShipArray[i];
	}

	delete playerShip;

	LOG(INFO) << "Game was closed";

	return 0;
}
