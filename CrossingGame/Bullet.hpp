#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet
{
private:
	float bulRadius;
	sf::CircleShape* shape;
	float deltaTime;
	sf::Clock clock;
	void _initVar();
	void _initBullet();
	void GetDeltaTime();
public:
	Bullet();
	~Bullet();
	sf::CircleShape* GetBulletShape();
	void setPositionBullet(sf::Vector2f);
	void setPositionBullet(float, float);
	void updateBullet();
};

