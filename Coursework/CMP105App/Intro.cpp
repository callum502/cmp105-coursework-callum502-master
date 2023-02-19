#include "Intro.h"

Intro::Intro(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects


	howToPlayTexture.loadFromFile("gfx/how to play.png");
	howToPlay.setTexture(&howToPlayTexture);
	howToPlay.setSize(sf::Vector2f(1340, 1054));
	howToPlay.setPosition(window->getSize().x / 2 - 670, window->getSize().y / 2 - 500);

}

Intro::~Intro()
{

}

// handle user input
void Intro::handleInput(float dt, Level &level)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		if (level.fromPause)
		{
			gameState->setCurrentState(State::PAUSE);
			level.fromPause = false;
		}
		else
		{
			gameState->setCurrentState(State::LEVEL);
			level.player.spawnpoint.x = 96;
			level.player.spawnpoint.y = 896;
			level.checkpoint[0].passed = false;
			level.checkpoint[1].passed = false;
			for (int i = 0; i < level.coins; i++)
			{
				level.coin[i].collected = false;
			}
			level.reset();
		}
	}
}

// Update game objects
void Intro::update(float dt)
{
	view = window->getView();
	view.setCenter(window->getSize().x / 2, window->getSize().y / 2);
	window->setView(view);
}

// Render level
void Intro::render()
{
	beginDraw();
	window->draw(howToPlay);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Intro::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Intro::endDraw()
{
	window->display();
}
