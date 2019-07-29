#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Bullet : public sf::Sprite
{
	public:
		Bullet(int);
		virtual ~Bullet();
		void playSound();
		bool shouldBeDrawed;
		int getBulletId();
	protected:

	private:
		int bulletId;
		sf::Texture *bulletTexture;
		sf::SoundBuffer *soundBuffer;
		sf::Sound *sound;
};

#endif // BULLET_H
