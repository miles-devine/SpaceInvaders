#ifndef ENEMY_H
#define ENEMY_h
#include "raylib.h"

class Enemy {
	public:
		Enemy();
		Enemy(int type, float x_float, float y_float);
		void draw();
		void updatex(int direction);
		void updatey(int amount);
		bool get_status();
		Rectangle get_rectangle();
		int speed = 1;
		Vector2 position;
		Texture2D texture;
	private:
		bool active = true;
		Rectangle rect;
	};

#endif // ENEMY_h