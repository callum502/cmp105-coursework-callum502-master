#pragma once
#include "Enemy.h"
class BulletBill : public Enemy
{
public:
	BulletBill();
	void update(float dt);
	void tileResponse(GameObject* collider);
	Animation fly;


};

