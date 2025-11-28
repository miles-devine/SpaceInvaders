#ifndef LASER_H
#define LASER_H

#include "raylib.h"

class Laser {
	public:
		Laser();
		Laser(int type, int x, int y);
		Rectangle get_rectangle();
		Vector2 position;
		float speed;
		void draw();
		void update();
		int height = 10;
		int width = 4;
		bool active = true;
		// int get type
	private:
		Rectangle rect;
		// int type
};

#endif // LASER_H