#include "raylib-cpp.hpp"
#include "iostream"
#include "player.hpp"
#include "mesh.hpp"
#include "myTexture.hpp"
#include "fence.hpp"
#include "enemy.hpp"
#include <vector>
#include <utility> //for pair

using namespace std;

void fillMap(char map[25][25]){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            map[i][j] = '0';
        }
    }
    map[8][8] = 'X';
    map[8][6] = 'X';
    map[6][8] = 'X';
}

void renderMap(char map[25][25]){
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25; j++){
            if(map[i][j] == '0'){
                DrawRectangle(i*32, j*32, 32, 32, GREEN);
            }
            else if(map[i][j] == 'X'){
                DrawRectangle(i*32, j*32, 32, 32, BLUE);
            }
        }
    }
}
void drawHuds(const Texture2D& bar)
{
    DrawText("GTU VALLEY", 640, 10, 20, RED);
    DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 250, 113, BLUE);
    DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
    DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
    DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
    DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);

    DrawRectangleLines( 30, 350, 170, 83, BLACK);
    DrawRectangle( 30, 350, 170, 83, Fade(DARKGRAY, 0.5f));
    DrawTexture(bar, -10, 320, WHITE);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------

    int screenWidth = 800;
    int screenHeight = 450;
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

    char map[25][25];
    fillMap(map);
    player pl;
    // pl.addTexture("walkL", (Vector2){6, 1}, LoadTexture("sprites/characters/walkL.png"), 40, 40);
    // pl.addTexture("walkR", (Vector2){6, 1}, LoadTexture("sprites/characters/walkR.png"), 40, 40); // 1 ,6 here is the row and column count of frames in the spritesheet
    // pl.addTexture("walkU", (Vector2){6, 1}, LoadTexture("sprites/characters/walkU.png"), 40, 40);
    // pl.addTexture("walkD", (Vector2){6, 1}, LoadTexture("sprites/characters/walkD.png"), 40, 40);
    // pl.addTexture("stand", (Vector2){6, 1}, LoadTexture("sprites/characters/stand.png"), 40, 40); // 1 ,6 here is the row and column count of frames in the spritesheet
    
    pl.addTexture("walkL", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 40, 40);
    pl.addTexture("walkR", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 40, 40); // 1 ,6 here is the row and column count of frames in the spritesheet
    pl.addTexture("walkU", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 40, 40);
    pl.addTexture("walkD", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 40, 40);
    pl.addTexture("stand", (Vector2){1, 1}, LoadTexture("sprites/lol.png"), 40, 40);
    pl.setSpeed(2);
    pl.setPosition((Vector2){ 128, 128 });
    pl.setHitbox((Rectangle){ 4, 4, 24, 24});

    // fence fen;
    // fen.setPosition((Vector2){ 480, 360 });
    // fen.setHitbox((Rectangle){ 480.7f, 362.5f, 11.5f, 10 });
    // fen.addTexture(string("default"), (Vector2){ 1, 1 }, LoadTexture("assets/fences/fencesingle.png"), 40, 40);
    Enemy en;
    // en.addTexture("stand", (Vector2){6, 1}, LoadTexture("sprites/characters/stand.png"), 40, 40);
    en.setPosition((Vector2){ 256, 128 });
    en.setHitbox((Rectangle){ 4, 4, 24, 24});


    //-------------------------------------------------------------------------------------
    //SET CAMERA
    //-------------------------------------------------------------------------------------
    // int spacing = 0;
    // Camera2D camera = { 0 };
    // camera.target = pl.getPosition();
    // camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    // camera.rotation = 0.0f;
    // camera.zoom = 2.32f;
    //-------------------------------------------------------------------------------------
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {   
        if(IsWindowResized()){
            screenHeight = GetScreenHeight();
            screenWidth = GetScreenWidth();
            numTilesX = screenWidth / floor.width ;
            numTilesY = screenHeight / floor.height;
        }
        // Update
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
        
         if(IsWindowResized()){
            
            numTilesX = screenWidth / floor.width ;
            numTilesY = screenHeight / floor.height;
        }    
            



        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

       ClearBackground(RAYWHITE);
            renderMap(map);
            pl.drawRec(pl.getCurrentTexture());
            DrawRectangle(pl.getPositionX()+pl.getHitbox().x, pl.getPositionY()+pl.getHitbox().y, pl.getHitbox().width, pl.getHitbox().height, Fade(LIGHTGRAY, 0.5f));
            std::cout << pl.getPosition().x << " " << pl.getPosition().y << std::endl;
            // BeginMode2D(camera);
            //     pl.drawRec(pl.getCurrentTexture());
            //     fen.drawRec("default");
            //     // DrawRectangleRec(pl.getHitbox(), Fade(LIGHTGRAY, 0.5f));
            //     // DrawRectangleRec(en.getHitbox(), Fade(RED, 0.5f));
            //     // en.drawRec("stand");
            //     // en.move(pl);
            // EndMode2D();
            drawHuds(bar);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}