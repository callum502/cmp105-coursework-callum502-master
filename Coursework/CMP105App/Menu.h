#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Level.h"
#include <string>
#include <iostream>


class Menu {
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Menu();

	void handleInput(float dt);
	void update(float dt, Level &level);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for Menu class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	GameObject playButton;
	GameObject playgodButton;
	GameObject title;

	sf::Texture titleTexture;
	sf::Texture playButtonTexture;
	sf::Texture playgodButtonTexture;
	sf::View view;
};