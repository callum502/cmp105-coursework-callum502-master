#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects

	playButtonTexture.loadFromFile("gfx/start.png");
	playButton.setTexture(&playButtonTexture);
	playButton.setSize(sf::Vector2f(512, 128));
	playButton.setPosition(window->getSize().x / 2 - 256, window->getSize().y / 2 - 64);

	playgodButtonTexture.loadFromFile("gfx/god start.png");
	playgodButton.setTexture(&playgodButtonTexture);
	playgodButton.setSize(sf::Vector2f(512, 128));
	playgodButton.setPosition(window->getSize().x / 2 - 256, window->getSize().y / 2 + 128);

	titleTexture.loadFromFile("gfx/Title.png");
	title.setTexture(&titleTexture);
	title.setSize(sf::Vector2f(1426, 98));
	title.setPosition(window->getSize().x / 2 - 713, window->getSize().y / 2 - 300);
}

Menu::~Menu()
{

}

// handle user input
void Menu::handleInput(float dt)
{
}

// Update game objects
void Menu::update(float dt, Level &level)
{
	view = window->getView();
	view.setCenter(window->getSize().x / 2, window->getSize().y / 2);
	window->setView(view);
	if (audio->getMusic()->getStatus() == sf::Music::Stopped)
	{
		audio->playMusicbyName("menu");
	}
	if (input->isMouseLDown())
	{
		if (input->getMouseX() > playButton.getPosition().x && input->getMouseX() < playButton.getPosition().x + playButton.getSize().x)
		{
			if (input->getMouseY() > playButton.getPosition().y && input->getMouseY() < playButton.getPosition().y + playButton.getSize().y)
			{
				level.player.godmode = false;
				level.switchGod.setTexture(&level.godOnTexture);
				gameState->setCurrentState(State::INTRO);
			}
			else if (input->getMouseY() > playgodButton.getPosition().y && input->getMouseY() < playgodButton.getPosition().y + playgodButton.getSize().y)
			{
				level.player.godmode = true;
				level.switchGod.setTexture(&level.godOffTexture);
				gameState->setCurrentState(State::INTRO);
			}
		}
	}
}

// Render level
void Menu::render()
{
	beginDraw();
	window->draw(playButton);
	window->draw(playgodButton);
	window->draw(title);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Menu::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Menu::endDraw()
{
	window->display();
}
