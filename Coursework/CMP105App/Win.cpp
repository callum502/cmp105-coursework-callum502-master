#include "Win.h"

Win::Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	if (!font.loadFromFile("font/SuperMario256.ttf"))
	{
		std::cout << "error";
	}

	text.setFont(font);
	text.setString("You managed to collect");
	text.setCharacterSize(64);
	text.setPosition(window->getSize().x / 2 - 922, window->getSize().y / 2 -25);
	text.setFillColor(sf::Color(128,0,128));

	number.setFont(font);
	number.setCharacterSize(64);
	number.setFillColor(sf::Color(128, 0, 128));
	number.setPosition(window->getSize().x / 2 + 68, window->getSize().y / 2 -25);

	text2.setFont(font);
	text2.setString("/50 coins well done");
	text2.setCharacterSize(64);
	text2.setFillColor(sf::Color(128, 0, 128));
	text2.setPosition(window->getSize().x / 2 + 158, window->getSize().y / 2 - 25);

	congratsTexture.loadFromFile("gfx/congrats.png");
	congrats.setTexture(&congratsTexture);
	congrats.setSize(sf::Vector2f(1171, 93));
	congrats.setPosition(window->getSize().x / 2 - 585, window->getSize().y / 2 - 400);

	enterTexture.loadFromFile("gfx/press enter.png");
	enter.setTexture(&enterTexture);
	enter.setSize(sf::Vector2f(1541, 70));
	enter.setPosition(window->getSize().x / 2 - 770, window->getSize().y / 2 + 300);


}

Win::~Win()
{

}

// handle user input
void Win::handleInput(float dt, Level &level)
{
	if (!music)
	{
		audio->stopAllMusic();
		audio->stopAllSounds();
		audio->playMusicbyName("win");
		music = true;
		number.setString(std::to_string(level.player.coins));	
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		gameState->setCurrentState(State::MENU);
		audio->stopAllMusic();
		music = false;
	}
}

// Update game objects
void Win::update(float dt)
{
	view = window->getView();
	view.setCenter(window->getSize().x / 2, window->getSize().y / 2);
	window->setView(view);
}

// Render level
void Win::render()
{
	beginDraw();
	window->draw(text);
	window->draw(text2);
	window->draw(number);
	window->draw(congrats);
	window->draw(enter);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Win::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Win::endDraw()
{
	window->display();
}
