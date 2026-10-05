#include <raylib.h>
int main(void) {
	SetTargetFPS(60);
	Rectangle player = {0, 300, 100, 100};
	Rectangle enemy = {325, 125, 100, 100};
	Rectangle enemy_bottom = {325, 225, 100, 1};
	Rectangle enemy_top = {325, 125, 100, 1};
	Rectangle enemy_left = {325, 125, 1, 100};
	Rectangle enemy_right = {425, 125, 1, 100};
	InitWindow(800, 400, "jogo");
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if(IsKeyDown(KEY_D)) {
			player.x += 5;
		}
		if(IsKeyDown(KEY_A)) {
			player.x -= 5;
		}
		if(IsKeyDown(KEY_W)) {
			player.y -= 5;
		}
		if(IsKeyDown(KEY_S)) {
			player.y += 5;
		}
		if(player.x < 0) {
			player.x += 5;
		}
		if(player.x > 800 - player.width) {
			player.x -= 5;
		}
		if(player.y < 0) {
			player.y += 5;
		}
		if(player.y > 400 - player.height) {
			player.y -= 5;
		}
		if(CheckCollisionRecs(player, enemy_bottom)) {
			player.y += 1;
		}
		if(CheckCollisionRecs(player, enemy_top)) {
			player.y -= 1;
		}
	       	if(CheckCollisionRecs(player, enemy_left)) {
			player.x -= 1;
		}
	       	if(CheckCollisionRecs(player, enemy_right)) {
			player.x += 1;
		}
		DrawRectangleRec(player, YELLOW);
		DrawRectangleRec(enemy, RED);
		DrawRectangleRec(enemy_top, BLUE);
		DrawRectangleRec(enemy_bottom, PINK);
		DrawRectangleRec(enemy_right, BROWN);
		DrawRectangleRec(enemy_left, GREEN);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
