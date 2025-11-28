#include "ship.h"
#include <iostream>

Ship::Ship() {
 texture = LoadTexture("graphics/spaceship.png");
 position.x = (GetScreenWidth() - texture.width) / 2;
 position.y = GetScreenHeight() - texture.height;
 rect.x = position.x;
 rect.y = position.y;
};

Ship::~Ship () {

};

void Ship::draw() {
	DrawTextureV(texture, position, WHITE);
}

void Ship::move_left() {
	position.x -= speed;

	if (position.x <= 0) {
		position.x = 0;
	}
};

void Ship::move_right() {
	position.x += speed;

	if (position.x >= GetScreenWidth() - texture.width) {
		position.x = GetScreenWidth() - texture.width;
	}
};
// Don't think this needs to be a pointer acrtually but lets see --> does need to be a pointer. We need to manager this
void Ship::shoot_laser() {
	if (GetTime() - last_shot > 0.1) { // Variable here for the shot time, no magic numbers
		Laser* laser = new Laser(0,position.x + (texture.width / 2), position.y - texture.height);
		laser->draw();
		lasers.push_back(laser);
		last_shot = GetTime();
	}
}

void Ship::disable_lasers() {
	if (!lasers.empty()) {
		for (auto laser : lasers) {
			if (laser->position.y < 0) {
				laser->active = false;
			}
		}
	}
}

void Ship::delete_lasers() {
	if (!lasers.empty()) {
		for (auto it = lasers.begin(); it != lasers.end();) {
			if (!(*it)->active || (*it)->position.y < 0) {
				delete *it;
				it = lasers.erase(it);
				std::cout << "Number of lasers: " << lasers.size() << "\n";
			}
			else {
				it++;
			}
		}
	}
}