#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class EnemyShip : public sf::Sprite
{
	public:
		EnemyShip();
		virtual ~EnemyShip();
		void playSound();
		bool shouldBeDrawed;

	protected:

	private:
		sf::Texture *enemyShipTexture;
		sf::SoundBuffer * soundBuffer;
		sf::Sound * sound;
};

#endif // ENEMYSHIP_H
