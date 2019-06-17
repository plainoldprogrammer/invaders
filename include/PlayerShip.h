#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SFML/Graphics.hpp>


class PlayerShip : public sf::Sprite
{
	public:
		PlayerShip();
		virtual ~PlayerShip();
		void moveLeft();
		void moveRight();
	protected:

	private:
		sf::Texture *playerShipTexture;
};

#endif // PLAYERSHIP_H
