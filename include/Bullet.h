#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>


class Bullet : public sf::Sprite
{
	public:
		Bullet();
		virtual ~Bullet();

	protected:

	private:
		sf::Texture *bulletTexture;
};

#endif // BULLET_H
