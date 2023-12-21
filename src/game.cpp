#include "game.hpp"
#include <unistd.h>
// map 600 600 olacak
#ifndef SIZE
#define SIZE 128
#endif

void Game::fillEnemy()
{
	// map[5][4] = new Enemy("enemy", Vector2{4 * 32, 5 * 32}, (Rectangle){4, 4, 24, 24});
	// Enemy *en = dynamic_cast<Enemy *>(map[5][4]);
	// en->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
	// map[7][9] = new Enemy("enemy", Vector2{9 * 32, 7 * 32}, (Rectangle){4, 4, 24, 24});
	// en = dynamic_cast<Enemy *>(map[7][9]);
	// en->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
	// map[11][3] = new Enemy("enemy", Vector2{3 * 32, 11 * 32}, (Rectangle){4, 4, 24, 24});
	// en = dynamic_cast<Enemy *>(map[11][3]);
	// en->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);


	//enemies[0] = (dynamic_cast<Enemy *>(map[5][4]));
	//enemies.push_back(dynamic_cast<Enemy *>(map[5][4]));
	//enemies.push_back(dynamic_cast<Enemy *>(map[7][9]));
	//enemies.push_back(dynamic_cast<Enemy *>(map[11][3]));
	enemies.push_back(new Enemy("enemy", Vector2{4 * 32, 5 * 32}, (Rectangle){4, 4, 24, 24}));
	enemies[0]->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
	enemies.push_back(new Enemy("enemy", Vector2{9 * 32, 7 * 32}, (Rectangle){4, 4, 24, 24}));
	enemies[1]->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
	enemies.push_back(new Enemy("enemy", Vector2{3 * 32, 11 * 32}, (Rectangle){4, 4, 24, 24}));
	enemies[2]->addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);

	//std::cout << (dynamic_cast<Enemy *>(map[5][4])) << std::endl;
	//std::cout << (dynamic_cast<Enemy *>(map[5][4])) << std::endl;
	//std::cout << &enemies[0] << std::endl;
}

void Game::initMap()
{
	for (int i = 0; i < SIZE; i++)
	{
		vector<mesh *> tmp;
		for (int j = 0; j < SIZE; j++)
		{
			tmp.push_back(new mesh());
		}
		map.push_back(tmp);
	}
	fillEnemy();
	map[20][20] = new fence();
}

void Game::renderMap() const
{
	Texture2D texture = LoadTexture("sprites/ground.png");
	for (int i = 0; i < (SIZE); i++)
	{
		for (int j = 0; j < (SIZE); j++)
		{
			DrawTexture(texture, j * 32, i * 32, WHITE);
			if (map[i][j]->getName() == "fence")
			{
				DrawRectangle(j * 32, i * 32, 32, 32, PURPLE); // meshinkini kullan
			}
		}
	}
}

Game::Game() : width(SIZE * 32), height(SIZE * 32), pl(this), enemies({})
{
	initMap();
	initTextures();
}

void Game::drawHuds() const
{
	DrawText("GTU VALLEY", GetScreenWidth() - 140, 10, 20, RED);
	DrawRectangle(640, 28, 80, 30, Fade(BLACK, 0.5f));
	DrawFPS(640, 30);
	DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines(10, 10, 250, 113, BLUE);
	DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
	DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
	DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
	DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
	DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);

	// DrawRectangleLines(30, 350, 170, 83, BLACK);
	// DrawRectangle(30, 350, 170, 83, Fade(DARKGRAY, 0.5f));
	// DrawTexture(bar, -10, 320, WHITE); // can barı
}

void Game::initTextures()
{
	pl.addTexture("walkL", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 32, 32);
	pl.addTexture("walkR", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 32, 32); // 1 ,6 here is the row and column count of frames in the spritesheet
	pl.addTexture("walkU", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 32, 32);
	pl.addTexture("walkD", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 32, 32);
	pl.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 32, 32);
	ground.addTexture("default", (Vector2){1, 1}, LoadTexture("sprites/ground.png"), 32, 32);

	// daha tex var enemy
}

void Game::run()
{
	//-------------------------------------------------------------------------------------
	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose()) // Detect window close button or ESC key
	{

		// if(IsWindowResized()){
		//     screenHeight = GetScreenHeight();
		//     screenWidth = GetScreenWidth();
		//     numTilesX = screenWidth / floor.width ;
		//     numTilesY = screenHeight / floor.height;
		// }
		//  Update
		// if (IsKeyPressed(KEY_P))
		// 	pause();
		
		pl.getTextures()["stand"].getCurrentFrame();
		pl.move(map);
		//----------------------------------------------------------------------------------
		// Player movement
		// pl.move(fen);
		// Camera target follows player
		// camera.target = pl.getPosition();

		// Camera rotation controls
		// if (IsKeyDown(KEY_A)) camera.rotation--;
		// else if (IsKeyDown(KEY_S)) camera.rotation++;

		// // Limit camera rotation to 80 degrees (-40 to 40)
		// if (camera.rotation > 40) camera.rotation = 40;
		// else if (camera.rotation < -40) camera.rotation = -40;

		// // Camera zoom controls
		// camera.zoom += ((float)GetMouseWheelMove()*0.05f);

		// if (camera.zoom > 3.0f) camera.zoom = 3.0f;
		// else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

		// // Camera reset (zoom and rotation)
		// if (IsKeyPressed(KEY_R))
		// {
		//     camera.zoom = 1.0f;
		//     camera.rotation = 0.0f;
		// }
		//----------------------------------------------------------------------------------

		// if(IsWindowResized()){
		//
		//    numTilesX = screenWidth / floor.width ;
		//    numTilesY = screenHeight / floor.height;
		//}
		int pX;
		int pY;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Vector2 mousePos = GetMousePosition();
			pl.setPositionX(mousePos.x);
			pl.setPositionY(mousePos.y);
		}
		else if  (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			Vector2 mousePos = GetMousePosition();
			pX = mousePos.x / 32;
			pY = mousePos.y / 32;
			map[pY][pX] = new fence();
		}


		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		renderMap();
		pl.drawRec(pl.getCurrentTexture());
    	DrawRectangle((int)((pl.getPositionX() + 16)/ 32) * 32, (int)((pl.getPositionY() + 16 )/ 32)*32, 32, 32, Fade(YELLOW, 0.5f));
		DrawRectangleLines(pl.getPositionX() + pl.getHitbox().x, pl.getPositionY() + pl.getHitbox().y, pl.getHitbox().width, pl.getHitbox().height, Fade(LIGHTGRAY, 0.5f));
		// BeginMode2D(camera);
		//     pl.drawRec(pl.getCurrentTexture());
		//     fen.drawRec("default");
		//     // DrawRectangleRec(pl.getHitbox(), Fade(LIGHTGRAY, 0.5f));
		//     // DrawRectangleRec(en.getHitbox(), Fade(RED, 0.5f));
		// en.drawRec("stand");
		// en.move(pl, map);
		// en1.drawRec("stand");
		// en1.move(pl, map);
		// en2.drawRec("stand");
		// en2.move(pl, map);
		// en3.drawRec("stand");
		// en3.move(pl, map);

		// EndMode2D();
		for (auto& en : enemies)
		{
			en->drawRec("stand");
			DrawRectangleLines(en->getPositionX() + en->getHitbox().x, en->getPositionY() + en->getHitbox().y, en->getHitbox().width, en->getHitbox().height, Fade(RED, 0.5f));
			en->move(pl, map);
		}
		drawHuds();
		if (IsKeyDown(KEY_SPACE))
		{
			Vector2 mousePos = GetMousePosition();
			pX = mousePos.x / 32;
			pY = mousePos.y / 32;
			DrawRectangle(pX * 32, pY * 32, 32, 32, Fade(GRAY, 0.5f));
			DrawText("BURDA", pX*32, pY*32, 20, RED);
		}
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow(); // Close window and OpenGL context
				   //--------------------------------------------------------------------------------------
}
