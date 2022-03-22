#pragma once
#include<vector>
#include"Enemy.hpp"
#include"Bullet.hpp"

class EnemyManager
{
private:
	std::vector<Enemy> enemy;
	void _initVars();
	void _initEnemyManager();
public:
	EnemyManager();
	~EnemyManager();
	std::vector<Enemy>& GetEnemies();
	void MoveEnemies();
	void RenderEnemies(sf::RenderTarget*);
	void updateEnemies();
	void EnemyHit(Bullet&);
};

