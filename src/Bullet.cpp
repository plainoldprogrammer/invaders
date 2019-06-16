#include "easylogging++.h"
#include "Bullet.h"


Bullet::Bullet()
{
    bulletTexture = new sf::Texture();
    bulletTexture->loadFromFile("textures/bullet.png");
    this->setTexture(*bulletTexture);
    this->setTextureRect(sf::IntRect(0, 0, 8, 8));
    this->setPosition(0, 0);

    LOG(INFO) << "Bullet was created";
}

Bullet::~Bullet()
{
    //dtor
}
