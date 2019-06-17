#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <SFML/Graphics.hpp>


class EnemyShip : public sf::Sprite
{
	public:
		EnemyShip();
		virtual ~EnemyShip();

	protected:

	private:
		sf::Texture *enemyShipTexture;
};

#endif // ENEMYSHIP_H
