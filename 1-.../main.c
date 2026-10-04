#include <raylib.h>
int main(void) {
	InitWindow(800, 400, "jogo");
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
