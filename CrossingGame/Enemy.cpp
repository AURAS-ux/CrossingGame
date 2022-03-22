#include "Enemy.hpp"
#include<iostream>

void Enemy::_initVars(sf::Vector2f position)
{
	this->enemySize.x = 80;
	this->enemySize.y = 80;
	this->enemyPos = position;
	this->enemyTexture = new sf::Texture();
	this->enemyShape = sf::RectangleShape();
	this->hitboxShape = sf::RectangleShape();
}

void Enemy::_initEnemy()
{
	this->enemyShape.setPosition(enemyPos);
	this->enemyShape.setSize(enemySize);
	this->enemyShape.setFillColor(sf::Color::White);
	this->hitboxShape.setPosition(this->enemyShape.getPosition().x+10, this->enemyShape.getPosition().y + 5);
	this->hitboxShape.setFillColor(sf::Color::Transparent);
	this->hitboxShape.setSize(sf::Vector2f(60,60));
	this->hitboxShape.setOutlineColor(sf::Color::White);
	this->hitboxShape.setOutlineThickness(0.5f);
	if (this->enemyTexture->loadFromFile("Assets/enemy.png")) {
		this->enemyShape.setTexture(enemyTexture);
	}
}

Enemy::Enemy(sf::Vector2f Epos)
{
	_initVars(Epos);
	_initEnemy();
}

Enemy::Enemy()
{
	_initVars(sf::Vector2f::Vector2(950,50));
	_initEnemy();
}

Enemy::~Enemy()
{
}

void Enemy::renderEnemy(sf::RenderTarget* tr)
{
	tr->draw(this->enemyShape);
	tr->draw(this->hitboxShape);
}

void Enemy::setPosition(float x, float y)
{
	this->enemyPos.x = x;
	this->enemyPos.y = y;
}

sf::RectangleShape& Enemy::GetEnemy()
{
	return this->enemyShape;
}

sf::RectangleShape& Enemy::GetHitBox()
{
	return this->hitboxShape;
}

void Enemy::MoveEnemy()
{
	if (this->enemyShape.getPosition().x < 1920)
	{
		this->enemyShape.move(1.f, 0);
		this->hitboxShape.move(1.f, 0);
	}
	else if (this->enemyShape.getPosition().x > 1920)
	{
		this->enemyShape.move(-1.f, 0);
		this->hitboxShape.move(-1.f, 0);
	}
}
