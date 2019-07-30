#include "easylogging++.h"
#include "Bullet.h"


Bullet::Bullet(int id)
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

	this->shouldBeDrawed = true;

	bulletId = id;
	LOG(INFO) << "Bullet #" << this->bulletId << " was created";
}

Bullet::~Bullet()
{
	LOG(INFO) << "Call to the Bullet #" << this->bulletId << " destructor";
	delete sound;
	delete soundBuffer;
	delete bulletTexture;
}

void Bullet::playSound()
{
	sound->play();
}

int Bullet::getBulletId()
{
	return this->bulletId;
}
