#include "Goomba.h"
Goomba::Goomba()
{
	scale = 200.0f;

	walk.addFrame(sf::IntRect(2, 18, 19, 22));
	walk.addFrame(sf::IntRect(24, 18, 19, 22));
	walk.addFrame(sf::IntRect(46, 18, 19, 22));
	walk.addFrame(sf::IntRect(68, 18, 19, 22));
	walk.addFrame(sf::IntRect(90, 18, 19, 22));
	walk.setFrameSpeed(1.f / 6.f);
}

void Goomba::update(float dt)
{

	//change direction
	if (left)
	{
		setVelocity(-250, 0);
		walk.setFlipped(true);
	}
	else
	{
		setVelocity(250, 0);
		walk.setFlipped(false);
	}

	//walk
	move(velocity * dt);

	//get Lpoint/Rpoint
	Lpoint.x = getPosition().x;
	Lpoint.y = getPosition().y + getSize().y;
	Rpoint.x = getPosition().x + getSize().x;
	Rpoint.y = getPosition().y + getSize().y;

	//animate
	setTextureRect(walk.getCurrentFrame());
	walk.animate(dt);
}

