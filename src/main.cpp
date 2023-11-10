#include "raylib-cpp.hpp"
#include "iostream"
#include "player.hpp"
#include "mesh.hpp"
#include "myTexture.hpp"
#include "fence.hpp"
#include <vector>
#include <utility> //for pair

using namespace std;


// void downSprite(Texture2D& img_tex, int& d, Image* down)
// {

//     UnloadTexture(img_tex);
//     if (d % 60 <= 10)
//         img_tex = LoadTextureFromImage(down[0]);
//     else if (d % 60 <= 20)
//         img_tex = LoadTextureFromImage(down[1]);
//     else if (d % 60 <= 30)
//         img_tex = LoadTextureFromImage(down[2]);
//     else if (d % 60 <= 40)
//         img_tex = LoadTextureFromImage(down[3]);
//     else if (d % 60 <= 50)
//         img_tex = LoadTextureFromImage(down[4]);
//     else if (d % 60 <= 60)
//         img_tex = LoadTextureFromImage(down[5]);
//     img_tex.width = 40;
//     img_tex.height = 40;
//     d++;
// }

// void upSprite(Texture2D& img_tex, int& u, Image* up)
// {
//     UnloadTexture(img_tex);
//     if (u % 60 <= 10)
//         img_tex = LoadTextureFromImage(up[0]);
//     else if (u % 60 <= 20)
//         img_tex = LoadTextureFromImage(up[1]);
//     else if (u % 60 <= 30)
//         img_tex = LoadTextureFromImage(up[2]);
//     else if (u % 60 <= 40)
//         img_tex = LoadTextureFromImage(up[3]);
//     else if (u % 60 <= 50)
//         img_tex = LoadTextureFromImage(up[4]);
//     else if (u % 60 <= 60)
//         img_tex = LoadTextureFromImage(up[5]);
//     img_tex.width = 40;
//     img_tex.height = 40;
//     u++;
// }

// void rightSprite(Texture2D& img_tex, int& r, Image* rw)
// {
//     UnloadTexture(img_tex);
//     if (r % 60 <= 10)
//         img_tex = LoadTextureFromImage(rw[0]);
//     else if (r % 60 <= 20)
//         img_tex = LoadTextureFromImage(rw[1]);
//     else if (r % 60 <= 30)
//         img_tex = LoadTextureFromImage(rw[2]);
//     else if (r % 60 <= 40)
//         img_tex = LoadTextureFromImage(rw[3]);
//     else if (r % 60 <= 50)
//         img_tex = LoadTextureFromImage(rw[4]);
//     else if (r % 60 <= 60)
//         img_tex = LoadTextureFromImage(rw[5]);
//     img_tex.width = 40;
//     img_tex.height = 40;
//     r++;
// }

// void leftSprite(Texture2D& img_tex, int& wlk, Image* walk)
// {
//     UnloadTexture(img_tex);
//     if (wlk % 60 <= 10)
//         img_tex = LoadTextureFromImage(walk[0]);
//     else if (wlk % 60 <= 20)
//         img_tex = LoadTextureFromImage(walk[1]);
//     else if (wlk % 60 <= 30)
//         img_tex = LoadTextureFromImage(walk[2]);
//     else if (wlk % 60 <= 40)
//         img_tex = LoadTextureFromImage(walk[3]);
//     else if (wlk % 60 <= 50)
//         img_tex = LoadTextureFromImage(walk[4]);
//     else if (wlk % 60 <= 60)
//         img_tex = LoadTextureFromImage(walk[5]);
//     img_tex.width = 40;
//     img_tex.height = 40;
//     wlk++;
// }

// void defaultSprite(Texture2D& img_tex, int& spt, Image* character)
// {
//     UnloadTexture(img_tex);
//     if (spt % 60 <= 10)
//         img_tex = LoadTextureFromImage(character[0]);
//     else if (spt % 60 <= 20)
//         img_tex = LoadTextureFromImage(character[1]);
//     else if (spt % 60 <= 30)
//         img_tex = LoadTextureFromImage(character[2]);
//     else if (spt % 60 <= 40)
//         img_tex = LoadTextureFromImage(character[3]);
//     else if (spt % 60 <= 50)
//         img_tex = LoadTextureFromImage(character[4]);
//     else if (spt % 60 <= 60)
//         img_tex = LoadTextureFromImage(character[5]);
//     img_tex.width = 40;
//     img_tex.height = 40;
//     spt++;
// }

// void slimeSprite(Texture2D& slm, int& slc, Image* slime)
// {
//     UnloadTexture(slm);
//     if (slc % 60 <= 10)
//         slm = LoadTextureFromImage(slime[0]);
//     else if (slc % 60 <= 20)
//         slm = LoadTextureFromImage(slime[1]);
//     else if (slc % 60 <= 30)
//         slm = LoadTextureFromImage(slime[2]);
//     else if (slc % 60 <= 40)
//         slm = LoadTextureFromImage(slime[3]);
//     else if (slc % 60 <= 50)
//         slm = LoadTextureFromImage(slime[4]);
//     else if (slc % 60 <= 60)
//         slm = LoadTextureFromImage(slime[5]);
//     slm.width = 40;
//     slm.height = 40;
//     slc++;
// }

// void attackSprite(Texture2D& atck, int& at, Image* attack)
// {
//     UnloadTexture(atck);
//     if (at % 16 <= 4)
//         atck = LoadTextureFromImage(attack[0]);
//     else if (at % 16 <= 8)
//         atck = LoadTextureFromImage(attack[1]);
//     else if (at % 16 <= 12)
//         atck = LoadTextureFromImage(attack[2]);
//     else if (at % 16 <= 16)
//         atck = LoadTextureFromImage(attack[3]);
//     atck.width = 40;
//     atck.height = 40;
//     at++;
// }

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------

    const int screenWidth = 800;
    const int screenHeight = 450;
    int spt = 0;
    int wlk = 0;
    int spd = 1;
    int u = 0;
    int d = 0;
    int r = 0;
    int at = 0;
    InitWindow(screenWidth, screenHeight, "csgo");
    Texture2D floor = LoadTexture("assets/grass.png");
    floor.width = 40;
    floor.height = 45;

    player pl;   
    pl.addTexture("walkL", (Vector2){6, 1}, LoadTexture("sprites/characters/walkL.png"), 40, 40);
    pl.addTexture("walkR", (Vector2){6, 1}, LoadTexture("sprites/characters/walkR.png"), 40, 40); // 1 ,6 here is the row and column count of frames in the spritesheet
    pl.addTexture("walkU", (Vector2){6, 1}, LoadTexture("sprites/characters/walkU.png"), 40, 40);
    pl.addTexture("walkD", (Vector2){6, 1}, LoadTexture("sprites/characters/walkD.png"), 40, 40);
    pl.addTexture("stand", (Vector2){6, 1}, LoadTexture("sprites/characters/stand.png"), 40, 40); // 1 ,6 here is the row and column count of frames in the spritesheet
    pl.setSpeed(2);
    pl.setPosition((Vector2){ 400, 280 });
    pl.setHitbox((Rectangle){ 400, 280, 50, 50 });
    fence fen;
    fen.setPosition((Vector2){ 480, 360 });
    fen.setHitbox((Rectangle){ 480, 360, 40, 40 });
    fen.addTexture(string("default"), (Vector2){ 1, 1 }, LoadTexture("assets/fences/fencesingle.png"), 40, 40);

    //-------------------------------------------------------------------------------------
    //SET IMAGES
    // //-------------------------------------------------------------------------------------
    // Image character[6];   // Load image in CPU memory (RAM)
    // Image walk[6];
    // Image up[6];
    // Image down[6];
    // Image rw[6];
    // Image fencetek = LoadImage("assets/fences/fencesingle.png");
    // Image slime[6];
    // Image attack[4];
    // Image floor = LoadImage("assets/grass.png");   // Load image in CPU memory (RAM)
    // fillImages(character, walk, up, down, rw, slime, attack);
    //-------------------------------------------------------------------------------------


    //-------------------------------------------------------------------------------------
    //SET TEXTURES
    //-------------------------------------------------------------------------------------
    // Texture2D img_tex = LoadTextureFromImage(character[0]);
    // Texture2D img_tex2 = LoadTextureFromImage(floor);
    // Texture2D ft = LoadTextureFromImage(fencetek);
    // Texture2D slm;
    // Texture2D atck;
    //-------------------------------------------------------------------------------------


    //-------------------------------------------------------------------------------------
    //SET CAMERA
    //-------------------------------------------------------------------------------------
    int spacing = 0;
    Camera2D camera = { 0 };
    camera.target = pl.getPosition();
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 2.0f;
    //-------------------------------------------------------------------------------------
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        pl.getTextures()["stand"].getCurrentFrame();
        //----------------------------------------------------------------------------------
        // Player movement
        pl.move();
        // Camera target follows player
        camera.target = pl.getPosition();

        // Camera rotation controls
        if (IsKeyDown(KEY_A)) camera.rotation--;
        else if (IsKeyDown(KEY_S)) camera.rotation++;

        // Limit camera rotation to 80 degrees (-40 to 40)
        if (camera.rotation > 40) camera.rotation = 40;
        else if (camera.rotation < -40) camera.rotation = -40;

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);

        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (int i = 0; i < 20; i++)
                for (int j = 0 ; j < 10; j++)
                    DrawTexture(floor, i*40, j*45, WHITE);
            BeginMode2D(camera);
                pl.drawRec(pl.getCurrentTexture());
                fen.drawRec("default");
            EndMode2D();
            DrawText("GTU VALLEY", 640, 10, 20, RED);
            DrawRectangle( 10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 250, 113, BLUE);
            DrawText("Free 2d camera controls:", 20, 20, 10, BLACK);
            DrawText("- Right/Left to move Offset", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse Wheel to Zoom in-out", 40, 60, 10, DARKGRAY);
            DrawText("- A / S to Rotate", 40, 80, 10, DARKGRAY);
            DrawText("- R to reset Zoom and Rotation", 40, 100, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}