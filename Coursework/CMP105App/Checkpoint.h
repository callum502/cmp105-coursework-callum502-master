#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Checkpoint : public GameObject
{
public:
	Animation wave;
	bool passed;
	Checkpoint();
	void update(float dt);
};

