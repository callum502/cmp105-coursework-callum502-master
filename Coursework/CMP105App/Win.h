#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Level.h"
#include <string>
#include <iostream>


class Win {
public:
	Win(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Win();

	void handleInput(float dt, Level &level);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for Win class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	GameObject congrats;
	GameObject enter;
	bool music;

	sf::Texture congratsTexture;
	sf::Texture enterTexture;
	sf::Font font;
	sf::Text text;
	sf::Text text2;
	sf::Text number;
	sf::View view;
};