#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "HammerBro.h"
class Hammer : public GameObject
{
public:
	Hammer();
	void update(float dt, HammerBro hb);
	Animation spin;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	float acceleration;
	//constructor random velocity
	//update move, apply gravity
};

