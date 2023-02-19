#include "Death.h"


Death::Death(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	// initialise game objects
	youDiedTexture.loadFromFile("gfx/you died.png");
	youDied.setTexture(&youDiedTexture);
	youDied.setSize(sf::Vector2f(1249, 216));
	youDied.setPosition(window->getSize().x / 2 - 624, window->getSize().y / 2 - 108);
}

Death::~Death()
{
}

// handle user input
void Death::handleInput(float dt, Level &level)
{
	if (!music)
	{
		audio->stopAllMusic();
		audio->playMusicbyName("death");
		music = true;
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		gameState->setCurrentState(State::LEVEL);
		audio->stopAllSounds();
		music = false;
		level.reset();
	}
}

// Update game objects
void Death::update(float dt)
{
	view = window->getView();
	view.setCenter(window->getSize().x / 2, window->getSize().y / 2);
	window->setView(view);
}

// Render level
void Death::render()
{
	beginDraw();
	window->draw(youDied);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Death::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Death::endDraw()
{
	window->display();
}
