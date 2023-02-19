#include "HammerBro.h"
HammerBro::HammerBro()
{
	toss.addFrame(sf::IntRect(180, 90, 16, 24));
	toss.addFrame(sf::IntRect(210, 90, 16, 24));
	toss.addFrame(sf::IntRect(240, 90, 16, 24));
	toss.setFrameSpeed(1.f / 6.f);
	toss.setFlipped(true);
}

void HammerBro::update(float dt)
{
	setTextureRect(toss.getCurrentFrame());
	toss.animate(dt);
}