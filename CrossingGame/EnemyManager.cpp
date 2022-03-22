#include "EnemyManager.hpp"


void EnemyManager::_initVars()
{
	this->enemyModel = Enemy();
	this->enemy = std::vector<Enemy>();
}

void EnemyManager::_initEnemyManager()
{
	for (int i = 0; i < 20; i++)
	{
		this->enemy.push_back(Enemy(enemyModel));
	}
}

EnemyManager::EnemyManager()
{
	this->_initVars();
	this->_initEnemyManager();
}

EnemyManager::~EnemyManager()
{
}

std::vector<Enemy> EnemyManager::GetEnemies()
{
	return enemy;
}

void EnemyManager::MoveEnemies()
{
	for (auto& e : enemy)
	{
		e.MoveEnemy();
	}
}


void EnemyManager::RenderEnemies(sf::RenderTarget* target)
{
	for (auto& enemie : enemy)
	{
		enemie.renderEnemy(target);
	}
}

void EnemyManager::updateEnemies()
{
	this->MoveEnemies();
}

void EnemyManager::EnemyHit(Bullet& bullet)
{
	for (int i = 0; i < enemy.size();i++) {
		if (bullet.GetBulletShape().getGlobalBounds().intersects(enemy.at(i).GetHitBox().getGlobalBounds()))
		{
			enemy.erase(enemy.begin()+i);
		}
	}
}
