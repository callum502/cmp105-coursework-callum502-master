#pragma once
#include "Enemy.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/Collision.h"
#include "Framework/AudioManager.h"

class Player : public GameObject
{
public:
	Player();
	void handleInput(float dt, Input &in, AudioManager &audio);
	void update(float dt, sf::View &view, GameState& gs);
	void tileResponse(GameObject* collider);
	void enemyResponse(Enemy &collider, GameState &gs, AudioManager& audio);
	void coinResponse(GameObject &coin, sf::Text &coinDisplay);

	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;

	sf::Vector2f spawnpoint;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	Animation walk;
	Animation stand;
	Animation jump;
	Animation attack;
	Animation* currentAnimation;
	bool left;
	long xdiff;
	long ydiff;
	enum class state {standing, walking, jumping, attacking};
	state currentState;
	int coins;
	bool godmode;
};

