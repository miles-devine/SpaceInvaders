#include "laser.h"

Laser:: Laser() {

};

Laser::Laser(int type, int x, int y) {
	rect.x = x;
	rect.y = y;
	position.x = rect.x;
	position.y = rect.y;
	rect.height = height;
	rect.width = width;
	if (type == 0) {
		speed = -5; // ship laser
	}

	else {
		speed = 2; // enemy laser
	}
}

void Laser::draw() {
	DrawRectangleRec(rect, PURPLE);
}

void Laser::update() {
	position.y += speed;
	rect.y = position.y;
};

Rectangle Laser::get_rectangle() {
	return rect;
}