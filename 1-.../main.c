#include <raylib.h>
int main(void) {
	InitWindow(800, 400, "jogo");
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(200, 400, 10, 10, RED);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
