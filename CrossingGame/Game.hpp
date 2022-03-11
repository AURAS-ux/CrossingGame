#pragma once
#include<SFML/Graphics.hpp>
#include"Player.hpp"
#include<iostream>
class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;
	Player* playerShip;
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
};

