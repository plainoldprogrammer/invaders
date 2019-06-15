#include "easylogging++.h"
#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
    playerShipTexture = new sf::Texture();
    playerShipTexture->loadFromFile("textures/player-ship.png");
    this->setTexture(*playerShipTexture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    //this->setPosition(0, 0);

    LOG(INFO) << "PlayerShip() was created";
}

PlayerShip::~PlayerShip()
{
    //dtor
}
