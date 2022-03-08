#include "Game.h"

void Game::_initVar()
{
	this->videomode.height = 1920;
	this->videomode.width = 1080;
	this->videomode.bitsPerPixel = 32;
}

void Game::_initWindow()
{
	this->window = new sf::RenderWindow();
	this->window->create(this->videomode, "Crossing Game", sf::Style::Fullscreen);
	this->window->setFramerateLimit(144);
}

bool Game::isRunning()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(ev)) 
	{
		if (ev.key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::gameRender()
{
	this->window->clear(sf::Color::Cyan);
	//code
	this->window->display();
}

Game::Game()
{
	_initVar();
	_initWindow();
}

Game::~Game()
{
	std::cout << "Game destructor called"<<"\n";
}

void Game::update()
{
	this->gameRender();
	this->pollEvents();

}
