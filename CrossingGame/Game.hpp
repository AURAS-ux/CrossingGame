#pragma once
#include<SFML/Graphics.hpp>
#include"Player.hpp"
#include<iostream>
#include"Bullet.hpp"
#include<vector>
#include"Enemy.hpp"
#include<memory>
#include"EnemyManager.hpp"
class Game
{
private:
	int height, width;
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;
	Player* playerShip;
	Bullet bulletModel;
	std::vector<Bullet>bullets;
	int shootTimer;
	EnemyManager manager;
	sf::Texture* backgroundTexture;
	sf::Sprite background;
	void _initVar();
	void _initWindow();
	void pollEvents();
	void gameRender();
	//....
public:
	Game();
	~Game();
	bool isRunning();
	void update();
	void Shooting();
	void MoveBul();
	void DeleteBullets();
};

