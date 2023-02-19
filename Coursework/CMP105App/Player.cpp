#include "Player.h"

Player::Player()
{
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	coins = 0;

	walk.addFrame(sf::IntRect(212, 199, 18, 32));
	walk.addFrame(sf::IntRect(242, 199, 18, 32));
	walk.addFrame(sf::IntRect(272, 199, 18, 32));
	walk.setFrameSpeed(1.f / 6.f);

	stand.addFrame(sf::IntRect(212, 279, 18, 32));
	stand.addFrame(sf::IntRect(212, 199, 18, 32));
	stand.setFrameSpeed(1.f / 2.f);

	jump.addFrame(sf::IntRect(302, 199, 18, 32));
	jump.setFrameSpeed(1.f / 1.f);
}

void Player::handleInput(float dt, Input &input, AudioManager &audio)
{
	//dont move in x direction if no buttons are being pressed
	setVelocity(0, getVelocity().y);
	//if left pressed move/animate moving left
	if (input.isKeyDown(sf::Keyboard::Left))
	{
		setVelocity(-3 * scale, getVelocity().y);
		left = 1;
		currentState = state::walking;
	}
	//right pressed moves/animates walking right
	if (input.isKeyDown(sf::Keyboard::Right))
	{
		setVelocity(3 * scale, getVelocity().y);
		left = 0;
		currentState = state::walking;
	}

	//if player is falling set state to jumping
	if (stepVelocity.y > 0)
	{
		currentState = state::jumping;
	}

	//if player not jumping press space to jump
	if (currentState != state::jumping)
	{
		if (input.isKeyDown(sf::Keyboard::Space))
		{
			setVelocity(getVelocity().x, -4 * scale);
			currentState = state::jumping;
			audio.playSoundbyName("jump");
		}
	}
	//if not moving set state to standing
	if (getVelocity().x == 0 && getVelocity().y == 0 && currentState != state::jumping)
	{
		currentState = state::standing;
	}
}

void Player::update(float dt, sf::View &view, GameState &gs)
{
	//move
	move(velocity * dt);

	//animate
	if (currentState == state::standing)
	{
		currentAnimation = &stand;
	}
	else if (currentState == state::walking)
	{
		currentAnimation = &walk;
	}
	else if (currentState == state::jumping)
	{
		currentAnimation = &jump;
	}

	if (left)
	{
		currentAnimation->setFlipped(true);
	}
	else
	{
		currentAnimation->setFlipped(false);
	}
	setTextureRect(currentAnimation->getCurrentFrame());
	currentAnimation->animate(dt);


	//apply gravity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	//keep in boundaries
	if (getPosition().y > 1216)
	{
		gs.setCurrentState(State::DEATH);
	}
}

void Player::tileResponse(GameObject* collider)
{
	double xdiff = (collider->getPosition().x + (collider->getSize().x / 2)) - (getPosition().x + (getSize().x / 2));
	double ydiff = (collider->getPosition().y + (collider->getSize().y / 2)) - (getPosition().y + (getSize().y / 2));
	// x axis
	if (abs(xdiff) > abs(ydiff))
	{
		//right side
		if (xdiff < 0)
		{
 			velocity.x = 0;
			setPosition(collider->getPosition().x + collider->getSize().x + 1, getPosition().y);
		}
		//left side
		else
		{
			velocity.x = 0;
			setPosition(collider->getPosition().x - getSize().x - 1, getPosition().y);
		}
	}
	//y axis
	else
	{
		//bottom side
		if (ydiff < 0)
		{
			velocity.y = 0;
			setPosition(getPosition().x, collider->getPosition().y + collider->getSize().y);
		}
		//top side
		else
		{
			currentState = state::standing;
			stepVelocity.y = 0;
			velocity.y = 0;
			setPosition(getPosition().x, collider->getPosition().y - getSize().y);
		}
	}
}

void Player::enemyResponse(Enemy &collider, GameState &gs, AudioManager &audio)
{
	xdiff = (collider.getPosition().x + (collider.getSize().x / 2)) - (getPosition().x + (getSize().x / 2));
	ydiff = (collider.getPosition().y + (collider.getSize().y / 2)) - (getPosition().y + (getSize().y / 2));

	// hits top
	if (abs(xdiff) < abs(ydiff) && ydiff>0)
	{
		stepVelocity.y = 0;
		velocity.y = -4 * scale;
		audio.playSoundbyName("jump");
		collider.setAlive(false);
	}
	else if (godmode)
	{
		collider.setAlive(false);
	}
	else
	{
		gs.setCurrentState(State::DEATH);
	}
}

void Player::coinResponse(GameObject &coin, sf::Text &coinDisplay)
{
	coin.setAlive(false);
	coins = coins + 1;
	coinDisplay.setString(std::to_string(coins));
}