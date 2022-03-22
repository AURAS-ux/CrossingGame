#include "Bullet.hpp"

void Bullet::_initVar()
{
	bulRadius = 10.f;
}

void Bullet::_initBullet()
{
	shape = sf::CircleShape(bulRadius);
	shape.setFillColor(sf::Color::Red);
}

void Bullet::GetDeltaTime()
{
	this->deltaTime = clock.restart().asSeconds();
}

Bullet::Bullet()
{
	_initVar();
	_initBullet();
}

Bullet::~Bullet()
{
	//std::cout << "Called bullet destructor"<<"\n";
}

sf::CircleShape& Bullet::GetBulletShape()
{
	return this->shape;
}

void Bullet::setPositionBullet(sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

void Bullet::setPositionBullet(float x, float y)
{
	this->shape.setPosition(x, y);
}

void Bullet::updateBullet(sf::Vector2f playerCenter)
{
	this->GetDeltaTime();
	this->shape.move(0,-10);
}
