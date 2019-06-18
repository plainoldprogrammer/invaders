#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Bullet : public sf::Sprite
{
	public:
		Bullet();
		virtual ~Bullet();
		void playSound();

	protected:

	private:
		sf::Texture *bulletTexture;
		sf::SoundBuffer *soundBuffer;
		sf::Sound *sound;
};

#endif // BULLET_H
