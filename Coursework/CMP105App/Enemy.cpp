#include "Enemy.h"
void Enemy::tileResponse(GameObject* collider, float dt)
{
	double xdiff = (getPosition().x + (getSize().x / 2)) - (collider->getPosition().x + (collider->getSize().x / 2));
	double ydiff = (getPosition().y + (getSize().y / 2)) - (collider->getPosition().y + (collider->getSize().y / 2));

	// x axis
	if (abs(xdiff) > abs(ydiff))
	{
		//right
		if (xdiff > 0)
		{
			velocity.x = 0;
			setPosition(collider->getPosition().x + collider->getSize().x + 1, getPosition().y);
			left = false;
		}
		//left
		else
		{
			velocity.x = 0;
			setPosition(collider->getPosition().x - getSize().x - 1, getPosition().y);
			left = true;
		}
	}
	//y axis
	else
	{
		//bottom
		if (ydiff > 0)
		{
			velocity.y = 0;
			setPosition(getPosition().x, collider->getPosition().y + collider->getSize().y);
		}
		//top
		else
		{
			velocity.y = 0;
			setPosition(getPosition().x, collider->getPosition().y - getSize().y);
		}
	}
}
