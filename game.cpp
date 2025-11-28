#include "game.h"
#include <iostream>

Game::Game() {
	initGame();

}

void Game::initGame() {
	ship = Ship();
	enemies = createEnemies();
}

void Game::update() {
	for (auto& laser:ship.lasers) {
		laser->update();
	}	
	moveEnemies();

	checkCollisions();
	ship.delete_lasers();
}

void Game::delete_enemies() {
	if (!enemies.empty()) {
		for (auto it = enemies.begin(); it != enemies.end();) {
			if (!it->get_status()) {
				it = enemies.erase(it);
			}
			else {
				it++;
			}
		}
	}
}

void Game::moveEnemies() {
	moveEnemiesSide();
	moveEnemiesDown();
}

void Game::moveEnemiesSide() { 
	for (auto& enemy: enemies) {
		if (enemy.position.x + enemy.texture.width > GetScreenWidth()) {
			enemy_direction = -2;
		}

		if (enemy.position.x < 0) {
			enemy_direction = 2;
		}

		enemy.updatex(enemy_direction);
	}

}

void Game::moveEnemiesDown() {
	if (GetTime() - movetimer > 1.5) {
		for (auto& enemy: enemies) {
			enemy.updatey(10);
			movetimer = GetTime();
		}
	}
}


// Add some variables here!!
// width is 38
std::vector<Enemy> Game::createEnemies() {
	std::vector<Enemy> enemies;
	for (int row = 0; row < 4; row ++) {
		for (int col = 0; col < 10; col++) {
			int enemy_type{};
			if (row == 0) {
				enemy_type = 1;
			}

			else if (row == 1) {
				enemy_type = 2;
			}

			else if (row == 2) {
				enemy_type = 3;
			}

			else if (row == 3) {
				enemy_type = 1;
			}
			
			float x = ((GetScreenWidth() / 11) + 19) +  55 * col;
			float y = 40 + 55 * row;

			enemies.push_back(Enemy(enemy_type,x,y));
		}
	}

	return enemies;
}

void Game::drawGame() {
	ship.draw();
	for (auto& enemy : enemies) {
    //std::cout << enemy.texture.width << std::endl;
}

	DrawFPS(GetScreenWidth()-100, GetScreenHeight()- 50);
	for (auto& laser: ship.lasers) {
		laser->draw();
	}
	for (auto& enemy: enemies) {
		enemy.draw();
	}
}

void Game::takeInput() {
	if (IsKeyDown(KEY_LEFT)) {
		ship.move_left();
	}
	if (IsKeyDown(KEY_RIGHT)) {
		ship.move_right();
	}
	if (IsKeyDown(KEY_SPACE)) {
		ship.shoot_laser();
	}
}

void Game::checkCollisions() { // Add some logic here to deal with the enemies getting too close to the ship
	for (auto laserIT = ship.lasers.begin(); laserIT != ship.lasers.end(); ++laserIT) {
		auto& laser = *laserIT;
	
	for (auto enemyIT = enemies.begin(); enemyIT != enemies.end();) {
		if (CheckCollisionRecs(enemyIT->get_rectangle(), laser->get_rectangle())) {
			enemyIT = enemies.erase(enemyIT);

			laser->active = false;

			break;
		}
		else {
			enemyIT++;
		}
	}
}
}
