#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"
#include "laser.h"
#include <vector>

class Ship
{
private:
	float speed = 7;
	Rectangle rect;
	Texture2D texture;
	Vector2 position;
	float last_shot{};
public:
	void draw();
	void shoot_laser();
	void disable_lasers(); // disables (sets to inactive) lasers that are off the screen
	void delete_lasers(); // deletes lasers that are inactive
	void move_left();
	void move_right();
	Ship(/* args */);
	~Ship();
	std::vector<Laser*> lasers;
};


#endif // SHIP_H