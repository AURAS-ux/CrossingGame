#include "Game.hpp"
using std::cout;

void Game::_initVar()
{
	this->height = 1080;
	this->width = 1920;
	this->videomode.height = height;
	this->videomode.width = width;
	this->videomode.bitsPerPixel = 32;
	this->playerShip = new Player();
	this->bulletModel =  Bullet();
	this->bullets = std::vector<Bullet>();
	this->shootTimer = 0;
	this->manager = EnemyManager();
	this->background = sf::Sprite();
	this->backgroundTexture = new sf::Texture();
	if (this->backgroundTexture->loadFromFile("Assets/space.png"))
	{
		this->background.setScale(1.875, 1.875);
		this->background.setTexture(*backgroundTexture);
	}
	else return;
}

void Game::_initWindow()
{
	this->window = new sf::RenderWindow();
	this->window->create(this->videomode, "LockON", sf::Style::Default);
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
		if (ev.type = sf::Event::Closed)
		{
			this->window->close();
		}
		else if (ev.key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::gameRender()
{
	this->window->clear(sf::Color::Black);
	//code
	this->window->draw(this->background);
	this->playerShip->RenderPlayer(this->window);
	for(auto& bullet :bullets )
	{
		this->window->draw(bullet.GetBulletShape());
	}
	for (auto& enem : manager.GetEnemies())
	{
		enem.renderEnemy(this->window);
	}
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
	delete this->window;
	delete this->playerShip;
	std::cout << "Game destructor called"<<"\n";
}

void Game::update()
{
	while (this->isRunning())
	{
		this->gameRender();
		this->pollEvents();
		this->playerShip->GetDeltaTime();
		this->playerShip->UpdatePlayer();
		if (shootTimer < 30)
			shootTimer++;
		if (shootTimer >= 30) {
			this->Shooting();
			shootTimer = 0;
		}
		this->MoveBul();
		this->DeleteBullets();
		this->manager.MoveEnemies();
		for (auto& b : bullets)
		{
			manager.EnemyHit(b);
		}
	}
}

void Game::Shooting()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		bulletModel.setPositionBullet(sf::Vector2f(this->playerShip->GetPlayerShape().getPosition().x+28.5f, this->playerShip->GetPlayerShape().getPosition().y));
		bullets.push_back(Bullet(bulletModel));
		//std::cout << bulletModel.GetBulletShape().getPosition().x << " " << bulletModel.GetBulletShape().getPosition().y << "\n";
	}
}

void Game::MoveBul()
{
	for (auto& bullet : bullets)
	{
		bullet.updateBullet(this->playerShip->GetPlayerShape().getPosition());
		//std::cout << bullets.size();
		//std::cout << bullet.GetBulletShape().getPosition().x << " " << bullet.GetBulletShape().getPosition().y << "\n";

	}
}

void Game::DeleteBullets()
{
	for (int i=0;i<bullets.size();i++)
	{
		if (bullets[i].GetBulletShape().getPosition().y < 0)
		{
			this->bullets.erase(bullets.begin()+i);
		}
	}
}
