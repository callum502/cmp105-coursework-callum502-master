#pragma once
#include "Enemy.h"
class HammerBro : public Enemy
{
public:
	void update(float dt);
	Animation toss;
	HammerBro();
};

