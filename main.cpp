/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
// #include "ship.h"
// #include "enemy.h"
#include "game.h"
// #include "laser.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "SPACE INVADERS");

    SetTargetFPS(60);
	Game game;
	// Laser laser(8, 500, 500);
	// Ship ship;
	// Enemy enemy(3, 50 ,50);

    while (!WindowShouldClose())
    {
        BeginDrawing();
		ClearBackground(BLACK);
		game.update();
		game.drawGame();
		game.takeInput();
		// laser.draw();
		// laser.update();
		// ship.draw();
		// ship.move_left();
		// ship.move_right();
		// enemy.draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}