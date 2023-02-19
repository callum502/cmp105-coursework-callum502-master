#include "Checkpoint.h"
Checkpoint::Checkpoint()
{
	passed = false;
	wave.addFrame(sf::IntRect(302, 233, 21, 21));
	wave.addFrame(sf::IntRect(302, 256, 21, 21));
	wave.setFrameSpeed(1.f / 2.f);
}

void Checkpoint::update(float dt)
{
	if (passed)
	{
		setTextureRect(wave.getCurrentFrame());
		wave.animate(dt);
	}
	else
	{
		setTextureRect(sf::IntRect(348, 256, 21, 21));
	}
}