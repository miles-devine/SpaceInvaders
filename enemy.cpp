#include "enemy.h"
#include <iostream>

Enemy::Enemy(int type, float x_float, float y_float) {
	switch(type) {
		case(1): texture = LoadTexture("graphics/alien_1.png");
		break;
		case(2): texture = LoadTexture("graphics/alien_2.png");
		break;
		case(3): texture = LoadTexture("graphics/alien_3.png");
		default: texture = LoadTexture("graphics/alien_3.png");
	}

	position.x = x_float;
	position.y = y_float;
	rect.height = texture.height;
	rect.width = texture.width;
	rect.x = position.x;
	rect.y = position.y;
	std::cout << texture.width;
}

void Enemy::draw() {
	DrawTextureV(texture,position,WHITE);
}

bool Enemy::get_status () {
	return active;
}

void Enemy::updatex(int direction) {
	position.x += direction;
	rect.x = position.x;
}

void Enemy::updatey(int amount) {
	position.y += amount;
	rect.y = position.y;
}

Rectangle Enemy::get_rectangle() {
	return rect;
}