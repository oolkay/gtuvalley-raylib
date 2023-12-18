#include "raylib-cpp.hpp"
#include "iostream"
#include "player.hpp"
#include "mesh.hpp"
#include "myTexture.hpp"
#include "fence.hpp"
#include "enemy.hpp"
#include "game.hpp"
#include <vector>
#include <utility> //for pair

using namespace std;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------

    int screenWidth = 800;
    int screenHeight = 800;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "csgo");
    Texture2D floor = LoadTexture("assets/grass.png");

    Texture2D hp = LoadTexture("sprites/particles/hp.png");
    Texture2D bar = LoadTexture("sprites/rpg.png");
    bar.height = 250;
    bar.width = 250;
    hp.height = 20;
    hp.width = 20;
    floor.width = 16;
    floor.height = 16;
    int numTilesX = screenWidth / floor.width ;
    int numTilesY = screenHeight / floor.height;

	Game game;

	game.run();

    // fence fen;
    // fen.setPosition((Vector2){ 480, 360 });
    // fen.setHitbox((Rectangle){ 480.7f, 362.5f, 11.5f, 10 });
    // fen.addTexture(string("default"), (Vector2){ 1, 1 }, LoadTexture("assets/fences/fencesingle.png"), 32, 32);

    // düşman amq
    //Enemy en;
    //en.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
    //en.setPosition((Vector2){ 256, 128 });
    //en.setHitbox((Rectangle){ 4, 4, 24, 24});
    //Enemy en1;
    //en1.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
    //en1.setPosition((Vector2){ 400, 500 });
    //en1.setHitbox((Rectangle){ 4, 4, 24, 24});
    //Enemy en2;
    //en2.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
    //en2.setPosition((Vector2){ 256, 500 });
    //en2.setHitbox((Rectangle){ 4, 4, 24, 24});
    //Enemy en3;
    //en3.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/ysa.png"), 32, 32);
    //en3.setPosition((Vector2){ 400, 128 });
    //en3.setHitbox((Rectangle){ 4, 4, 24, 24});


    //-------------------------------------------------------------------------------------
    //SET CAMERA
    //-------------------------------------------------------------------------------------
    // int spacing = 0;
    // Camera2D camera = { 0 };
    // camera.target = pl.getPosition();
    // camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    // camera.rotation = 0.0f;
    // camera.zoom = 2.32f;
    // //-------------------------------------------------------------------------------------
    // SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    // //--------------------------------------------------------------------------------------

    // // Main game loop
    // while (!WindowShouldClose())        // Detect window close button or ESC key
    // {
    //     if(IsWindowResized()){
    //         screenHeight = GetScreenHeight();
    //         screenWidth = GetScreenWidth();
    //         numTilesX = screenWidth / floor.width ;
    //         numTilesY = screenHeight / floor.height;
    //     }
    //     // Update
    //     pl.getTextures()["stand"].getCurrentFrame();
    //     pl.move(map);
    //     //----------------------------------------------------------------------------------
    //     // Player movement
    //     // pl.move(fen);
    //     // Camera target follows player
    //     // camera.target = pl.getPosition();

    //     // Camera rotation controls
    //     // if (IsKeyDown(KEY_A)) camera.rotation--;
    //     // else if (IsKeyDown(KEY_S)) camera.rotation++;

    //     // // Limit camera rotation to 80 degrees (-40 to 40)
    //     // if (camera.rotation > 40) camera.rotation = 40;
    //     // else if (camera.rotation < -40) camera.rotation = -40;

    //     // // Camera zoom controls
    //     // camera.zoom += ((float)GetMouseWheelMove()*0.05f);

    //     // if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    //     // else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

    //     // // Camera reset (zoom and rotation)
    //     // if (IsKeyPressed(KEY_R))
    //     // {
    //     //     camera.zoom = 1.0f;
    //     //     camera.rotation = 0.0f;
    //     // }
    //     //----------------------------------------------------------------------------------

    //      if(IsWindowResized()){

    //         numTilesX = screenWidth / floor.width ;
    //         numTilesY = screenHeight / floor.height;
    //     }




    //     // Draw
    //     //----------------------------------------------------------------------------------
    //     BeginDrawing();

    //    ClearBackground(RAYWHITE);
    //         renderMap(map);
    //         pl.drawRec(pl.getCurrentTexture());
    //         DrawRectangle(pl.getPositionX()+pl.getHitbox().x, pl.getPositionY()+pl.getHitbox().y, pl.getHitbox().width, pl.getHitbox().height, Fade(LIGHTGRAY, 0.5f));

    //         std::cout << pl.getPosition().x << " " << pl.getPosition().y << std::endl;
    //         // BeginMode2D(camera);
    //         //     pl.drawRec(pl.getCurrentTexture());
    //         //     fen.drawRec("default");
    //         //     // DrawRectangleRec(pl.getHitbox(), Fade(LIGHTGRAY, 0.5f));
    //         //     // DrawRectangleRec(en.getHitbox(), Fade(RED, 0.5f));
    //         //en.drawRec("stand");
    //         //en.move(pl, map);
    //         //en1.drawRec("stand");
    //         //en1.move(pl, map);
    //         //en2.drawRec("stand");
    //         //en2.move(pl, map);
    //         //en3.drawRec("stand");
    //         //en3.move(pl, map);

    //         // EndMode2D();
    //         drawHuds(bar);
    //     EndDrawing();
    //     //----------------------------------------------------------------------------------
    // }

    // // De-Initialization
    // //--------------------------------------------------------------------------------------
    // CloseWindow();        // Close window and OpenGL context
    // //--------------------------------------------------------------------------------------

    return 0;
}
