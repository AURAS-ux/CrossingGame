#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
class Bullet
{
private:
	float bulRadius;
	sf::CircleShape shape;
	float deltaTime;
	sf::Clock clock;
	sf::Vector2f aimDir;
	void _initVar();
	void _initBullet();
	void GetDeltaTime();
public:
	Bullet();
	virtual ~Bullet();
	sf::CircleShape GetBulletShape();
	void setPositionBullet(sf::Vector2f);
	void setPositionBullet(float, float);
	void updateBullet(sf::Vector2f);
};

