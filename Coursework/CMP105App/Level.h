#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Framework/TileMap.h"
#include "Player.h"
#include  "Goomba.h"
#include "BulletBill.h"
#include "HammerBro.h"
#include "Hammer.h"
#include "Checkpoint.h"
#include "Coin.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();
	void reset();
	Player player;
	Checkpoint checkpoint[2];
	Coin coin[50];
	int coins = 50;
	bool fromPause = false;
	GameObject switchGod;
	sf::Texture godOnTexture;
	sf::Texture godOffTexture;
private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	TileMap tileMap;
	GameObject tile;
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	bool menuMusicPlaying;
	int cannons = 2;
	int goombas = 8;
	int hammerBros = 4;
	Goomba goomba[8];
	GameObject cannon[2];
	HammerBro hammerBro[4];
	Hammer hammer[4];
	GameObject HUDCoin;
	BulletBill LbulletBill[2];
	BulletBill RbulletBill[2];
	GameObject door;
	GameObject doorTop;
	GameObject resumeButton;
	GameObject howToPlay;
	sf::Font font;
	sf::Text coinDisplay;

	sf::Texture howToPlayTexture;
	sf::Texture resumeTexture;
	sf::Texture playerTexture;
	sf::Texture goombaTexture;
	sf::Texture bgTexture;
	sf::Texture cannonTexture;
	sf::Texture enemiesTexture;
	sf::Texture tileMapTexture;
	sf::RectangleShape bg;
	sf::View view;
};