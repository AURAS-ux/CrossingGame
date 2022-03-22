#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Player
{
private:
	float xSize, ySize, xPos, yPos, deltaTime, movementSpeed;;
	sf::RectangleShape* shape;
	sf::Clock clock;
	sf::Texture* playerTexture;
	void _initVar();
	void _initPlayer();
public:
	Player();
	~Player();
	void RenderPlayer(sf::RenderTarget* );
	sf::RectangleShape GetPlayerShape();
	void Movement();
	void UpdatePlayer();
	void GetDeltaTime();
	void CheckBorderCollision();
};

