#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Level.h"
#include <string>
#include <iostream>


class Intro {
public:
	Intro(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Intro();

	void handleInput(float dt, Level &level);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for Intro class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	GameObject howToPlay;

	sf::Texture howToPlayTexture;
	sf::View view;
};