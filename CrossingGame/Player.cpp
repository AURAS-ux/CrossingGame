#include "Player.hpp"

void Player::_initVar()
{
	this->xSize = 40;
	this->ySize = 40;
	this->xPos = 960;
	this->yPos = 940;
	this->movementSpeed = 300;
}

void Player::_initPlayer()
{
	this->shape = new sf::RectangleShape();
	this->shape->setPosition(xPos, yPos);
	this->shape->setSize(sf::Vector2f(xSize, ySize));
}

Player::Player()
{
	_initVar();
	_initPlayer();
}

Player::~Player()
{
	delete this->shape;
	std::cout << "Player destructor called";
}

void Player::RenderPlayer(sf::RenderTarget* tr)
{
	tr->draw(*this->shape);
}

sf::RectangleShape Player::GetPlayerShape()
{
	return *this->shape;
}

void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape->move(-2*movementSpeed * deltaTime,0 );
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape->move(2*movementSpeed * deltaTime, 0);
	}
}

void Player::UpdatePlayer()
{
	this->Movement();
	this->CheckBorderCollision();
}

void Player::GetDeltaTime()
{
	this->deltaTime = clock.restart().asSeconds();
}

void Player::CheckBorderCollision()
{
	if (shape->getGlobalBounds().left <= 0)
	{
		this->shape->setPosition(0, this->shape->getGlobalBounds().top);
	}
	if (this->shape->getGlobalBounds().left + this->shape->getGlobalBounds().width >= 1920)
	{
		this->shape->setPosition(1920 - this->shape->getGlobalBounds().width, this->shape->getGlobalBounds().top);
	}
}
