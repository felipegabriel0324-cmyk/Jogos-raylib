#include <raylib.h>
int playerX = 0;
int playerY = 300;
int projetilX = 325;
int projetilY = 125;
void resetarProjetil(int projetilX, int projetilY) {
	projetilX = 325;
	projetilY = 125;
}
void lancarProjetil() {
	if(playerX > 400) {
		projetilX += 1;
	}else{
		projetilX -= 1;
	}
	if(playerY > 200) {
		projetilY += 1;
	}else {
		projetilY -= 1;
	}
}
int main(void) {
	SetTargetFPS(60);
	Rectangle player = {playerX, playerY, 100, 100};
	Rectangle enemy = {325, 125, 100, 100};
	Rectangle enemy_bottom = {325, 225, 100, 1};
	Rectangle enemy_top = {325, 125, 100, 1};
	Rectangle enemy_left = {325, 125, 1, 100};
	Rectangle enemy_right = {425, 125, 1, 100};
	Rectangle projetil = {projetilX, projetilY, 10, 10};
	InitWindow(800, 400, "jogo");
	while(!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if(IsKeyDown(KEY_D)) {
			playerX += 5;
		}
		if(IsKeyDown(KEY_A)) {
			playerX -= 5;
		}
		if(IsKeyDown(KEY_W)) {
			playerY -= 5;
		}
		if(IsKeyDown(KEY_S)) {
			playerY += 5;
		}
		if(player.x < 0) {
			playerX += 5;
		}
		if(player.x > 800 - player.width) {
			playerX -= 5;
		}
		if(player.y < 0) {
			playerY += 5;
		}
		if(player.y > 400 - player.height) {
			playerY -= 5;
		}
		if(CheckCollisionRecs(player, enemy_bottom)) {
			playerY += 5;
		}
		if(CheckCollisionRecs(player, enemy_top)) {
			playerY -= 5;
		}
	       	if(CheckCollisionRecs(player, enemy_left)) {
			playerX -= 5;
		}
	       	if(CheckCollisionRecs(player, enemy_right)) {
			playerX += 5;
		}
		lancarProjetil();
		if(IsKeyDown(KEY_R)) {
			resetarProjetil(projetilX, projetilY);
		}
		DrawRectangleRec(projetil, BLUE);
		DrawRectangleRec(player, YELLOW);
		DrawRectangleRec(enemy, RED);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
