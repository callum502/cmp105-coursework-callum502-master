#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Level.h"
#include <string>
#include <iostream>


class Death {
public:
	Death(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Death();

	void handleInput(float dt, Level &level);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for Death class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	GameObject youDied;
	bool music;

	sf::Texture youDiedTexture;
	sf::View view;
};