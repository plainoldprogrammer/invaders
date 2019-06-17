#include "easylogging++.h"
#include "PlayerShip.h"

#define DISPLACEMENT_VELOCITY 18


PlayerShip::PlayerShip()
{
	playerShipTexture = new sf::Texture();
	playerShipTexture->loadFromFile("textures/player-ship.png");
	this->setTexture(*playerShipTexture);
	this->setTextureRect(sf::IntRect(0, 0, 32, 32));
	this->setPosition(0, 0);

	LOG(INFO) << "PlayerShip was created";
}

PlayerShip::~PlayerShip()
{
	//dtor
}

void PlayerShip::moveLeft()
{
	this->setPosition(this->getPosition().x - DISPLACEMENT_VELOCITY, this->getPosition().y);
}

void PlayerShip::moveRight()
{
	this->setPosition(this->getPosition().x + DISPLACEMENT_VELOCITY, this->getPosition().y);
}
