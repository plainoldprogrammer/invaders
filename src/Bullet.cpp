#include "easylogging++.h"
#include "Bullet.h"


Bullet::Bullet()
{
	bulletTexture = new sf::Texture();
	bulletTexture->loadFromFile("textures/bullet.png");
	this->setTexture(*bulletTexture);
	this->setTextureRect(sf::IntRect(0, 0, 8, 8));
	this->setPosition(0, 0);

	soundBuffer = new sf::SoundBuffer();
	if (!soundBuffer->loadFromFile("sounds/gun-shoot.wav"))
	{
		LOG(INFO) << "Can't load gun-shoot.wav sound";
	}

	sound = new sf::Sound();
	sound->setBuffer(*soundBuffer);
	sound->setVolume(100);

	LOG(INFO) << "Bullet was created";
}

Bullet::~Bullet()
{
	free(sound);
	free(soundBuffer);
	free(bulletTexture);
}

void Bullet::playSound()
{
	sound->play();
}
