#include "Hammer.h"
Hammer::Hammer()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;

	spin.addFrame(sf::IntRect(264, 100, 8, 16));
	spin.addFrame(sf::IntRect(264, 87, 14, 8));
	spin.addFrame(sf::IntRect(284, 87, 8, 16));
	spin.addFrame(sf::IntRect(278, 108, 14, 8));
	spin.setFrameSpeed(1.f / 6.f);
}

void Hammer::update(float dt, HammerBro hb)
{
	//apply gravity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	//animate
	setTextureRect(spin.getCurrentFrame());
	spin.animate(dt);
	setCollisionBox(0, 0, getTextureRect().width * 4, getTextureRect().height * 4);
	setSize(sf::Vector2f(getTextureRect().width * 4, getTextureRect().height * 4));

	//move
	move(velocity * dt);

	//sets hammer back to hammerbro
	if (getPosition().y > hb.getPosition().y + 2250 && hb.getTextureRect().left < 200)
	{
		setPosition(hb.getPosition().x, hb.getPosition().y);
		stepVelocity.y = 0;
		setVelocity(-350, -600);
		setCollider(false);
	}
	//so hammer doesnt kill player immediatley after spawning
	if (getPosition().y < hb.getPosition().y - 75)
	{
		setCollider(true);
	}
}