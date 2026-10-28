#include <iostream>
#include <raylib.h>

int main()
{
	int windowWidth = 800;
	int windowHeight = 800;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(windowWidth, windowHeight, "cezenjine");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{

		BeginDrawing();

		ClearBackground(BLUE);

		EndDrawing();

	}

	return 0;
}
