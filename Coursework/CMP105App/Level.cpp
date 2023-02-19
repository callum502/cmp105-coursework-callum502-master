#include "Level.h"
#include <iostream>

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	// initialise game objects
	tileMapTexture.loadFromFile("gfx/Tile sheetT.png");
	goombaTexture.loadFromFile("gfx/GoombaT.png");
	bgTexture.loadFromFile("gfx/BG.png");
	enemiesTexture.loadFromFile("gfx/EnemiesT.png");

	reset();
	view = window->getView();
	tileMap.loadTexture("gfx/Tile sheetT.png");
	playerTexture.loadFromFile("gfx/Waluigi.gif");
	audio->addMusic("sfx/Undertale OST 002 - Start Menu.ogg", "menu");
	audio->addMusic("sfx/Undertale OST 016 - Nyeh Heh Heh!.wav", "Nyeh");
	audio->addMusic("sfx/Undertale OST 011 - Determination.wav", "death");
	audio->addMusic("sfx/Megalovania.ogg", "win");
	audio->addSound("sfx/SMB_jump-small.ogg", "jump");
	audio->getSound("jump")->setVolume(55);
	audio->addSound("sfx/coin.wav", "coin");
	audio->getSound("coin")->setVolume(40);

	howToPlayTexture.loadFromFile("gfx/how to play button.png");
	howToPlay.setTexture(&howToPlayTexture);
	howToPlay.setSize(sf::Vector2f(512, 128));

	resumeTexture.loadFromFile("gfx/resume Game.png");
	resumeButton.setTexture(&resumeTexture);
	resumeButton.setSize(sf::Vector2f(512, 128));

	godOnTexture.loadFromFile("gfx/turn god on.png");
	godOffTexture.loadFromFile("gfx/turn god off.png");
	switchGod.setSize(sf::Vector2f(512, 128));

	if (!font.loadFromFile("font/SuperMario256.ttf"))
	{
		std::cout << "error";
	}

	coinDisplay.setFont(font);
	coinDisplay.setCharacterSize(48);
	coinDisplay.setFillColor(sf::Color(128, 0, 128));

	HUDCoin.setTexture(&tileMapTexture);
	HUDCoin.setTextureRect(sf::IntRect(579, 73, 21, 21));
	HUDCoin.setSize(sf::Vector2f(64, 64));

	player.setTexture(&playerTexture);
	player.setSize(sf::Vector2f(72, 128));
	player.setCollisionBox(sf::FloatRect(1, 0, 70, 128));

	door.setTexture(&tileMapTexture);
	door.setTextureRect(sf::IntRect(394, 118, 21, 21));
	door.setSize(sf::Vector2f(128, 128));
	door.setCollisionBox(sf::FloatRect(0, 0, 96, 96));
	door.setPosition(10656, 416);

	doorTop.setTexture(&tileMapTexture);
	doorTop.setTextureRect(sf::IntRect(371, 118, 21, 21));
	doorTop.setSize(sf::Vector2f(128, 128));
	doorTop.setCollisionBox(sf::FloatRect(0, 0, 0, 0));
	doorTop.setPosition(10656, 288);

	for (int i = 0; i < 2; i++)
	{
		checkpoint[i].setTexture(&tileMapTexture);
		checkpoint[i].setSize(sf::Vector2f(80, 80));
		checkpoint[i].setCollisionBox(sf::FloatRect(0, 0, 80, 80));
	}
	checkpoint[0].setPosition(4312, 176);
	checkpoint[1].setPosition(6168, 240);


	for (int i = 0; i < coins; i++)
	{
		coin[i].setTexture(&tileMapTexture);
		coin[i].setTextureRect(sf::IntRect(579, 73, 21, 21));
		coin[i].setSize(sf::Vector2f(64, 64));
		coin[i].setCollisionBox(sf::FloatRect(0, 0, 64, 64));
	}

	coin[0].setPosition(711, 736);
	coin[1].setPosition(775, 736);
	coin[2].setPosition(839, 736);

	coin[3].setPosition(1408, 608);
	coin[4].setPosition(1472, 608);

	coin[5].setPosition(2592, 96);
	coin[6].setPosition(2656, 96);
	coin[7].setPosition(2720, 96);

	coin[8].setPosition(2912, 352);
	coin[9].setPosition(2976, 352);
	coin[10].setPosition(3040, 352);

	coin[11].setPosition(2944, 544);
	coin[12].setPosition(3008, 544);

	coin[13].setPosition(3456, 544);
	coin[14].setPosition(3520, 544);

	coin[15].setPosition(3776, 480);
	coin[16].setPosition(3840, 480);
	coin[17].setPosition(3904, 480);

	coin[18].setPosition(5088, 736);
	coin[19].setPosition(5152, 736);
	coin[20].setPosition(5216, 736);

	coin[21].setPosition(5312, 384);
	coin[22].setPosition(5376, 384);

	coin[23].setPosition(5440, 64);
	coin[24].setPosition(5504, 64);

	coin[25].setPosition(5440, 648);
	coin[26].setPosition(5504, 648);

	coin[27].setPosition(5568, 384);
	coin[28].setPosition(5632, 384);

	coin[29].setPosition(6592, 224);
	coin[30].setPosition(6528, 224);

	coin[31].setPosition(6912, 224);
	coin[32].setPosition(6972, 224);

	coin[33].setPosition(7104, 96);
	coin[34].setPosition(7168, 96);
	coin[35].setPosition(7232, 96);

	coin[36].setPosition(8128, 48);
	coin[37].setPosition(8192, 48);

	coin[38].setPosition(8448, 224);
	coin[39].setPosition(8512, 224);

	coin[40].setPosition(8640, 224);
	coin[41].setPosition(8704, 224);

	coin[42].setPosition(8960, 48);
	coin[43].setPosition(9024, 48);

	coin[44].setPosition(10368, 352);
	coin[45].setPosition(10432, 352);
	coin[46].setPosition(10496, 352);
	coin[47].setPosition(10368, 416);
	coin[48].setPosition(10432, 416);
	coin[49].setPosition(10496, 416);

	for (int i = 0; i < goombas; i++)
	{
		goomba[i].setTexture(&goombaTexture);
		goomba[i].setSize(sf::Vector2f(75, 75));
		goomba[i].setCollisionBox(sf::FloatRect(0, 0, 75, 75));
	}

	for (int i = 0; i < cannons; i++)
	{
		cannon[i].setTexture(&enemiesTexture);
		cannon[i].setTextureRect(sf::IntRect(30, 116, 16, 32));
		cannon[i].setSize(sf::Vector2f(64, 128));
		cannon[i].setCollisionBox(sf::FloatRect(0, 0, 64, 128));

		LbulletBill[i].setTexture(&enemiesTexture);
		LbulletBill[i].setSize(sf::Vector2f(75, 56));
		LbulletBill[i].setCollisionBox(sf::FloatRect(0, 0, 75, 56));
		LbulletBill[i].left = true;

		RbulletBill[i].setTexture(&enemiesTexture);
		RbulletBill[i].setSize(sf::Vector2f(75, 56));
		RbulletBill[i].setCollisionBox(sf::FloatRect(0, 0, 75, 56));
		RbulletBill[i].left = false;
	}
	cannon[0].setPosition(3264, 832);
	cannon[1].setPosition(8576, 192);

	for (int i = 0; i < hammerBros; i++)
	{
		hammerBro[i].setTexture(&enemiesTexture);
		hammerBro[i].setSize(sf::Vector2f(88, 88));
		hammerBro[i].setCollisionBox(sf::FloatRect(0, 0, 88, 88));
		hammer[i].setTexture(&enemiesTexture);
	}
	bg.setTexture(&bgTexture);
	bg.setSize(sf::Vector2f(view.getSize().x, view.getSize().y));
	std::vector<GameObject> tiles;
	for (int i = 0; i < 5; i++)
	{
		tile.setSize(sf::Vector2f(64, 64));
		tile.setCollisionBox(0, 0, 64, 64);
		tile.setCollider(true);
		tiles.push_back(tile);
	}

	tiles[0].setCollider(false);
	tiles[4].setCollider(false);

	tiles[0].setTextureRect(sf::IntRect(256, 348, 21, 21)); // air
	tiles[1].setTextureRect(sf::IntRect(72, 95, 21, 21)); // full grass
	tiles[2].setTextureRect(sf::IntRect(49, 118, 21, 21)); //full dirt
	tiles[3].setTextureRect(sf::IntRect(279, 26, 21, 21)); //full lava
	tiles[4].setTextureRect(sf::IntRect(302, 3, 21, 21)); //top lava

	tileMap.setTileSet(tiles);

	sf::Vector2u mapSize(170, 19);
	std::vector<int> map =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 0));
	tileMap.buildLevel();

}

Level::~Level()
{

}

void Level::reset()
{

	player.setPosition(player.spawnpoint.x, player.spawnpoint.y);
	player.coins = 0;

	for (int i = 0; i < coins; i++)
	{
		if (coin[i].collected)
		{
			coin[i].setAlive(false);
			player.coins++;
		}
		else
		{
			coin[i].setAlive(true);
		}
	}
	coinDisplay.setString(std::to_string(player.coins));


	for (int i = 0; i < goombas; i++)
	{
		goomba[i].setAlive(true);
		goomba[i].left = true;
	}
	goomba[0].setPosition(1664, 501);
	goomba[1].setPosition(2496, 117);
	goomba[2].setPosition(2816, 373);
	goomba[3].setPosition(5312, 885);
	goomba[4].setPosition(5056, 117);
	goomba[5].setPosition(6464, 245);
	goomba[6].setPosition(7040, 245);
	goomba[7].setPosition(8064, 309);

	for (int j = 0; j < cannons; j++)
	{
		LbulletBill[j].setAlive(true);
		RbulletBill[j].setAlive(true);
		LbulletBill[j].setPosition(cannon[j].getPosition().x - LbulletBill[j].getSize().x, cannon[j].getPosition().y + 4);
		RbulletBill[j].setPosition(cannon[j].getPosition().x + cannon[j].getSize().x, cannon[j].getPosition().y + 4);
	}

	hammerBro[0].setPosition(5696, 104);
	hammer[0].setPosition(5696, 104);
	hammerBro[1].setPosition(7424, 232);
	hammer[1].setPosition(7424, 232);
	hammerBro[2].setPosition(7712, 104);
	hammer[2].setPosition(7712, 104);
	hammerBro[3].setPosition(9440, 104);
	hammer[3].setPosition(9440, 104);
	for (int i = 0; i < hammerBros; i++)
	{
		hammerBro[i].setAlive(true);
		hammer[i].stepVelocity.y = 0;
	}
	audio->playMusicbyName("Nyeh");
}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt, *input, *audio);
	//pause if esc is pressed
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		gameState->setCurrentState(State::PAUSE);
	}
	if (gameState->getCurrentState() == State::PAUSE)
	{
		view.setCenter(player.getPosition().x, 546);
		window->setView(view);
		bg.setPosition(sf::Vector2f(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2));
		coinDisplay.setPosition(view.getCenter().x - (window->getSize().x / 2) + 65, view.getCenter().y - (window->getSize().y / 2));
		HUDCoin.setPosition(view.getCenter().x - (window->getSize().x / 2) + 5, view.getCenter().y - (window->getSize().y / 2));
		resumeButton.setPosition(view.getCenter().x - 256, window->getSize().y / 2 - 64);
		switchGod.setPosition(view.getCenter().x - 256, window->getSize().y / 2 + 128);
		howToPlay.setPosition(view.getCenter().x - 256, window->getSize().y / 2 + 320);
		if (!menuMusicPlaying)
		{
			audio->playMusicbyName("menu");
			menuMusicPlaying = true;
		}
		if (input->isMouseLDown())
		{
			if (input->getMouseX() > resumeButton.getPosition().x - view.getCenter().x + (view.getSize().x / 2)  && input->getMouseX() < resumeButton.getPosition().x + resumeButton.getSize().x - view.getCenter().x + (view.getSize().x / 2))
			{
				if (input->getMouseY() > resumeButton.getPosition().y - view.getCenter().y + (view.getSize().y / 2) && input->getMouseY()  < resumeButton.getPosition().y + resumeButton.getSize().y - view.getCenter().y + (view.getSize().y / 2))
				{
					audio->playMusicbyName("Nyeh");
					menuMusicPlaying = false;
					gameState->setCurrentState(State::LEVEL);
				}
				else if (input->getMouseY() > switchGod.getPosition().y - view.getCenter().y + (view.getSize().y / 2) && input->getMouseY() < switchGod.getPosition().y + switchGod.getSize().y - view.getCenter().y + (view.getSize().y / 2))
				{
					if (player.godmode)
					{
						player.godmode = false;
						switchGod.setTexture(&godOnTexture);
						input->setMouseLDown(false);
					}
					else
					{
						player.godmode = true;
						switchGod.setTexture(&godOffTexture);
						input->setMouseLDown(false);
					}
				}
				else if (input->getMouseY() > howToPlay.getPosition().y - view.getCenter().y + (view.getSize().y / 2) && input->getMouseY() < howToPlay.getPosition().y + howToPlay.getSize().y - view.getCenter().y + (view.getSize().y / 2))
				{
					fromPause = true;
					gameState->setCurrentState(State::INTRO);
				}
			}
		}
	}
}

// Update game objects
void Level::update(float dt)
{
	//update player
	player.update(dt, view, *gameState);
	//update alive goombas 
	for (int i = 0; i < goombas; i++)
	{
		if (goomba[i].isAlive())
		{
			goomba[i].update(dt);
			goomba[i].ledge = true;
			goomba[i].redge = true;
		}
	}

	for (int i = 0; i < hammerBros; i++)
	{
		if (hammerBro[i].isAlive())
		{
			hammerBro[i].update(dt);
			hammer[i].update(dt, hammerBro[i]);
		}
	}
	
	for (int i = 0; i < cannons; i++)
	{
			LbulletBill[i].update(dt);
			RbulletBill[i].update(dt);
	}

	//playmusic
	if (audio->getMusic()->getStatus() == sf::SoundSource::Paused)
	{
		audio->getMusic()->play();
	}

	//tile & player collision detection
	std::vector<GameObject>* world = tileMap.getLevel();

	for (int i = 0; i < (int)world->size(); i++)
	{
		// if collision check should occur
		if ((*world)[i].isCollider())
		{
			//check if player collilding with tile
			if (Collision::checkBoundingBox(&player, &(*world)[i]))
			{
				if ((*world)[i].getTextureRect().top == 26)
				{
					gameState->setCurrentState(State::DEATH);
				}
				else
				{
					player.tileResponse(&(*world)[i]);
				}
			}
			for (int j = 0; j < cannons; j++)
			{
				if (Collision::checkBoundingBox(&(*world)[i], &LbulletBill[j]))
				{
					LbulletBill[j].setPosition(cannon[j].getPosition().x - LbulletBill[j].getSize().x, cannon[j].getPosition().y + 4);
					LbulletBill[j].setAlive(true);
				}
				if (Collision::checkBoundingBox(&(*world)[i], &RbulletBill[j]))
				{
					RbulletBill[j].setPosition(cannon[j].getPosition().x + cannon[j].getSize().x, cannon[j].getPosition().y + 4);
					RbulletBill[j].setAlive(true);
				}
			}
			for (int j = 0; j< goombas; j++)
			{ 
				if (goomba[j].isAlive())
				{
					//check if goomba colliding with tile
					if (Collision::checkBoundingBox(&goomba[j], &(*world)[i]))
					{
						goomba[j].tileResponse(&(*world)[i], dt);
					}
					//check if left point of goomba colliding with any tile
					if (Collision::checkBoundingBox(&(*world)[i], goomba[j].Lpoint))
					{
						goomba[j].ledge = false;
					}
					//check if right point of goomba colliding with any tile
					if (Collision::checkBoundingBox(&(*world)[i], goomba[j].Rpoint))
					{
						goomba[j].redge = false;
					}
				}
			}
		}
	}
	//player cannon collision
	for (int i = 0; i < cannons; i++)
	{
		if (Collision::checkBoundingBox(&player, &cannon[i]))
		{
			player.tileResponse(&cannon[i]);
		}//player Lbullet collison
		if (LbulletBill[i].isAlive())
		{
			if (Collision::checkBoundingBox(&player, &LbulletBill[i]))
			{
				player.enemyResponse(LbulletBill[i], *gameState, *audio);
			}
		}
		//Rbullet collision
		if (RbulletBill[i].isAlive())
		{
			if (Collision::checkBoundingBox(&player, &RbulletBill[i]))
			{
				player.enemyResponse(RbulletBill[i], *gameState, *audio);
			}
		}
	}
	//for all goombas
	for (int i = 0; i < goombas; i++)
	{
		if (goomba[i].isAlive())
		{
			if (goomba[i].ledge)
			{
				goomba[i].left = false;
			}
			else if (goomba[i].redge)
			{
				goomba[i].left = true;
			}
			//player goomba collision
			if (Collision::checkBoundingBox(&player, &goomba[i]))
			{
				player.enemyResponse(goomba[i], *gameState, *audio);
			}
		}
	}

	for (int i = 0; i < hammerBros; i++)
	{
		if (hammerBro[i].isAlive())
		{
			if (Collision::checkBoundingBox(&player, &hammerBro[i]))
			{
				player.enemyResponse(hammerBro[i], *gameState, *audio);
			}
			if (hammer[i].isCollider())
			{
				if (Collision::checkBoundingBox(&player, &hammer[i]))
				{
					if (!player.godmode)
					{
						gameState->setCurrentState(State::DEATH);
					}
				}
			}
		}
	}

	for (int i = 0; i < coins; i++)
	{
		if (coin[i].isAlive())
		{
			if (Collision::checkBoundingBox(&player, &coin[i]))
			{
				player.coinResponse(coin[i], coinDisplay);
				audio->playSoundbyName("coin");
			}
		}
	}

	if (Collision::checkBoundingBox(&player, &door))
	{
		gameState->setCurrentState(State::WIN);
	}

	for (int i = 0; i < 2; i++)
	{
		if (Collision::checkBoundingBox(&player, &checkpoint[i]))
		{
			checkpoint[i].passed = true;
			player.spawnpoint.x = checkpoint[i].getPosition().x;
			player.spawnpoint.y = checkpoint[i].getPosition().y - 48;
			for (int j = 0; j < coins; j++)
			{
				if (!coin[j].isAlive())
				{
					coin[j].collected = true;
				}
			}
		}
		checkpoint[i].update(dt);
	}

	//move cam to player
	view.setCenter(player.getPosition().x, 546);
	window->setView(view);
	bg.setPosition(sf::Vector2f(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2));
	coinDisplay.setPosition(view.getCenter().x - (window->getSize().x / 2) + 65, view.getCenter().y - (window->getSize().y / 2));
	HUDCoin.setPosition(view.getCenter().x - (window->getSize().x / 2) + 5, view.getCenter().y - (window->getSize().y / 2));
	resumeButton.setPosition(view.getCenter().x - 256, window->getSize().y / 2 - 64);
	switchGod.setPosition(view.getCenter().x - 256, window->getSize().y / 2 + 128);
	howToPlay.setPosition(view.getCenter().x - 256, window->getSize().y / 2 + 320);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(bg);
	window->draw(door);
	window->draw(doorTop);
	for (int i = 0; i < coins; i++)
	{
		if (coin[i].isAlive())
		{
			window->draw(coin[i]);
		}
	}

	for (int i = 0; i < cannons; i++)
	{
		window->draw(cannon[i]);
		if (LbulletBill[i].isAlive())
		{
			window->draw(LbulletBill[i]);
		}
		if (RbulletBill[i].isAlive())
		{
			window->draw(RbulletBill[i]);
		}
	}
	for (int i =0; i < goombas; i++)
	{
		if (goomba[i].isAlive())
		{
			window->draw(goomba[i]);
		}
	}

	window->draw(player);
	for (int i = 0; i < 2; i++)
	{
		window->draw(checkpoint[i]);
	}
	tileMap.render(window);
	for (int i = 0; i < hammerBros; i++)
	{
		if (hammerBro[i].isAlive())
		{
			window->draw(hammerBro[i]);
			window->draw(hammer[i]);
		}
	}
	window->draw(coinDisplay);
	window->draw(HUDCoin);
	if (gameState->getCurrentState() == State::PAUSE)
	{
		window->draw(resumeButton);
		window->draw(switchGod);
		window->draw(howToPlay);
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}