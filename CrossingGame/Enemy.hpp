#pragma once
#include<SFML/Graphics.hpp>
class Enemy
{
private:
	sf::Vector2f enemySize;
	sf::Vector2f enemyPos;
	sf::RectangleShape enemyShape;
	sf::Texture* enemyTexture;
	sf::RectangleShape hitboxShape;
	void _initVars(sf::Vector2f);
	void _initEnemy();
public:
	Enemy(sf::Vector2f);
	Enemy();
	~Enemy();
	void renderEnemy(sf::RenderTarget* tr);
	void setPosition(float, float);
	sf::RectangleShape& GetEnemy();
	sf::RectangleShape& GetHitBox();
	void MoveEnemy();
};

