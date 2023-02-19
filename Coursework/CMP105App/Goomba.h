#pragma once
#include "Enemy.h"
class Goomba : public Enemy
{
public:
	void update(float dt);
	Goomba();
	float scale;
	bool ledge;
	bool redge;
	sf::Vector2i Lpoint;
	sf::Vector2i Rpoint;
	Animation walk;

};

