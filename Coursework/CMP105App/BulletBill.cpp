#include "BulletBill.h"
BulletBill::BulletBill()
{
	fly.addFrame(sf::IntRect(0, 125, 16, 14));
}

void BulletBill::update(float dt)
{
	//set velocity based on direction
	if (left)
	{
		setVelocity(-250, 0);
	}
	else
	{
		setVelocity(250, 0);
		fly.setFlipped(true);
	}
	//move
	move(velocity * dt);

	//animate
	fly.animate(dt);
	setTextureRect(fly.getCurrentFrame());

}