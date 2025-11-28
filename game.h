#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include "ship.h"
#include "laser.h"
#include <vector>

class Game {
	public:
		Game();
		void initGame();
		void drawGame();
		void takeInput();
		void update();
		// Some kind of method that sets lasers to inactive and removes them from the ship vector
		int enemy_direction = 1;
		private:
		void delete_enemies();
		void checkCollisions();
		void moveEnemies();
		void moveEnemiesSide();
		void moveEnemiesDown();
		std::vector<Enemy> createEnemies();
		std::vector<Enemy> enemies;
		Ship ship;
		Laser laser;
		float movetimer{};
		
};

#endif // GAME_H