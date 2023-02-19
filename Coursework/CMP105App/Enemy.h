#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Enemy : public GameObject
{
public:
	void tileResponse(GameObject* collider, float dt);
	bool left;
};

