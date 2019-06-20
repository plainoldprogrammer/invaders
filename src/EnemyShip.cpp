#include "easylogging++.h"
#include "EnemyShip.h"


EnemyShip::EnemyShip()
{
	enemyShipTexture = new sf::Texture();
	enemyShipTexture->loadFromFile("textures/enemy-ship.png");
	this->setTexture(*enemyShipTexture);
	this->setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->setPosition(0, 0),

	soundBuffer = new sf::SoundBuffer();
	if (!soundBuffer->loadFromFile("sounds/enemy-ship-explosion.wav"))
	{
		LOG(INFO) << "Can't load enemy-ship-explosion.wav sound";
	}

	sound = new sf::Sound();
	sound->setBuffer(*soundBuffer);
	sound->setVolume(100);

	this->shouldBeDrawed = true;

	LOG(INFO) << "EnemyShip was created";
}

EnemyShip::~EnemyShip()
{
	LOG(INFO) << "Call to the EnemyShip destructor";
	delete enemyShipTexture;
}

void EnemyShip::playSound()
{
	sound->play();
}

