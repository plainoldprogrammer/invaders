#include "easylogging++.h"
#include "EnemyShip.h"


EnemyShip::EnemyShip()
{
    enemyShipTexture = new sf::Texture();
    enemyShipTexture->loadFromFile("textures/enemy-ship.png");
    this->setTexture(*enemyShipTexture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(0, 0),

    LOG(INFO) << "EnemyShip was created";
}

EnemyShip::~EnemyShip()
{
    //dtor
}
