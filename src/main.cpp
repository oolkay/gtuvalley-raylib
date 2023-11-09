#include "raylib-cpp.hpp"
#include "iostream"
#include <vector>
#include <string>
#include <map>
#include <utility> //for pair

using namespace std;

/*
typedef struct s_player
{
    Texture2D texture;
    Vector2 position;
} t_player;

void fillImages(Image* character, Image* walk, Image* up, Image* down, Image* rw, Image* slime, Image* attack)
{
    character[0] = LoadImage("assets/character/sprite1.png");
    character[1] = LoadImage("assets/character/sprite2.png");
    character[2] = LoadImage("assets/character/sprite3.png");
    character[3] = LoadImage("assets/character/sprite4.png");
    character[4] = LoadImage("assets/character/sprite5.png");
    character[5] = LoadImage("assets/character/sprite6.png");
    walk[0] = LoadImage("assets/character/walk1.png");
    walk[1] = LoadImage("assets/character/walk2.png");
    walk[2] = LoadImage("assets/character/walk3.png");
    walk[3] = LoadImage("assets/character/walk4.png");
    walk[4] = LoadImage("assets/character/walk5.png");
    walk[5] = LoadImage("assets/character/walk6.png");
    up[0] = LoadImage("assets/character/up1.png");
    up[1] = LoadImage("assets/character/up2.png");
    up[2] = LoadImage("assets/character/up3.png");
    up[3] = LoadImage("assets/character/up4.png");
    up[4] = LoadImage("assets/character/up5.png");
    up[5] = LoadImage("assets/character/up6.png");
    down[0] = LoadImage("assets/character/down1.png");
    down[1] = LoadImage("assets/character/down2.png");
    down[2] = LoadImage("assets/character/down3.png");
    down[3] = LoadImage("assets/character/down4.png");
    down[4] = LoadImage("assets/character/down5.png");
    down[5] = LoadImage("assets/character/down6.png");
    rw[0] = LoadImage("assets/character/rw1.png");
    rw[1] = LoadImage("assets/character/rw2.png");
    rw[2] = LoadImage("assets/character/rw3.png");
    rw[3] = LoadImage("assets/character/rw4.png");
    rw[4] = LoadImage("assets/character/rw5.png");
    rw[5] = LoadImage("assets/character/rw6.png");
    slime[0] = LoadImage("assets/slime/slime1.png");
    slime[1] = LoadImage("assets/slime/slime2.png");
    slime[2] = LoadImage("assets/slime/slime3.png");
    slime[3] = LoadImage("assets/slime/slime4.png");
    slime[4] = LoadImage("assets/slime/slime5.png");
    slime[5] = LoadImage("assets/slime/slime6.png");
    attack[0] = LoadImage("assets/character/attack1.png");
    attack[1] = LoadImage("assets/character/attack2.png");
    attack[2] = LoadImage("assets/character/attack3.png");
    attack[3] = LoadImage("assets/character/attack4.png");
}

void downSprite(Texture2D& img_tex, int& d, Image* down)
{

    UnloadTexture(img_tex);
    if (d % 60 <= 10)
        img_tex = LoadTextureFromImage(down[0]);
    else if (d % 60 <= 20)
        img_tex = LoadTextureFromImage(down[1]);
    else if (d % 60 <= 30)
        img_tex = LoadTextureFromImage(down[2]);
    else if (d % 60 <= 40)
        img_tex = LoadTextureFromImage(down[3]);
    else if (d % 60 <= 50)
        img_tex = LoadTextureFromImage(down[4]);
    else if (d % 60 <= 60)
        img_tex = LoadTextureFromImage(down[5]);
    img_tex.width = 40;
    img_tex.height = 40;
    d++;
}

void upSprite(Texture2D& img_tex, int& u, Image* up)
{
    UnloadTexture(img_tex);
    if (u % 60 <= 10)
        img_tex = LoadTextureFromImage(up[0]);
    else if (u % 60 <= 20)
        img_tex = LoadTextureFromImage(up[1]);
    else if (u % 60 <= 30)
        img_tex = LoadTextureFromImage(up[2]);
    else if (u % 60 <= 40)
        img_tex = LoadTextureFromImage(up[3]);
    else if (u % 60 <= 50)
        img_tex = LoadTextureFromImage(up[4]);
    else if (u % 60 <= 60)
        img_tex = LoadTextureFromImage(up[5]);
    img_tex.width = 40;
    img_tex.height = 40;
    u++;
}

void rightSprite(Texture2D& img_tex, int& r, Image* rw)
{
    UnloadTexture(img_tex);
    if (r % 60 <= 10)
        img_tex = LoadTextureFromImage(rw[0]);
    else if (r % 60 <= 20)
        img_tex = LoadTextureFromImage(rw[1]);
    else if (r % 60 <= 30)
        img_tex = LoadTextureFromImage(rw[2]);
    else if (r % 60 <= 40)
        img_tex = LoadTextureFromImage(rw[3]);
    else if (r % 60 <= 50)
        img_tex = LoadTextureFromImage(rw[4]);
    else if (r % 60 <= 60)
        img_tex = LoadTextureFromImage(rw[5]);
    img_tex.width = 40;
    img_tex.height = 40;
    r++;
}

void leftSprite(Texture2D& img_tex, int& wlk, Image* walk)
{
    UnloadTexture(img_tex);
    if (wlk % 60 <= 10)
        img_tex = LoadTextureFromImage(walk[0]);
    else if (wlk % 60 <= 20)
        img_tex = LoadTextureFromImage(walk[1]);
    else if (wlk % 60 <= 30)
        img_tex = LoadTextureFromImage(walk[2]);
    else if (wlk % 60 <= 40)
        img_tex = LoadTextureFromImage(walk[3]);
    else if (wlk % 60 <= 50)
        img_tex = LoadTextureFromImage(walk[4]);
    else if (wlk % 60 <= 60)
        img_tex = LoadTextureFromImage(walk[5]);
    img_tex.width = 40;
    img_tex.height = 40;
    wlk++;
}

void defaultSprite(Texture2D& img_tex, int& spt, Image* character)
{
    UnloadTexture(img_tex);
    if (spt % 60 <= 10)
        img_tex = LoadTextureFromImage(character[0]);
    else if (spt % 60 <= 20)
        img_tex = LoadTextureFromImage(character[1]);
    else if (spt % 60 <= 30)
        img_tex = LoadTextureFromImage(character[2]);
    else if (spt % 60 <= 40)
        img_tex = LoadTextureFromImage(character[3]);
    else if (spt % 60 <= 50)
        img_tex = LoadTextureFromImage(character[4]);
    else if (spt % 60 <= 60)
        img_tex = LoadTextureFromImage(character[5]);
    img_tex.width = 40;
    img_tex.height = 40;
    spt++;
}

void slimeSprite(Texture2D& slm, int& slc, Image* slime)
{
    UnloadTexture(slm);
    if (slc % 60 <= 10)
        slm = LoadTextureFromImage(slime[0]);
    else if (slc % 60 <= 20)
        slm = LoadTextureFromImage(slime[1]);
    else if (slc % 60 <= 30)
        slm = LoadTextureFromImage(slime[2]);
    else if (slc % 60 <= 40)
        slm = LoadTextureFromImage(slime[3]);
    else if (slc % 60 <= 50)
        slm = LoadTextureFromImage(slime[4]);
    else if (slc % 60 <= 60)
        slm = LoadTextureFromImage(slime[5]);
    slm.width = 40;
    slm.height = 40;
    slc++;
}

void attackSprite(Texture2D& atck, int& at, Image* attack)
{
    UnloadTexture(atck);
    if (at % 16 <= 4)
        atck = LoadTextureFromImage(attack[0]);
    else if (at % 16 <= 8)
        atck = LoadTextureFromImage(attack[1]);
    else if (at % 16 <= 12)
        atck = LoadTextureFromImage(attack[2]);
    else if (at % 16 <= 16)
        atck = LoadTextureFromImage(attack[3]);
    atck.width = 40;
    atck.height = 40;
    at++;
}



*/


class myTexture{
    private:
        string _name;
        Vector2 _frameMatrix;
        Texture2D _texture;
        Rectangle _frame;
    public:
        myTexture(): _name("Default"), _frameMatrix(), _texture(){}
        myTexture(string name, Vector2 frameMatrix, Texture2D texture) : _name(name), _frameMatrix(frameMatrix), _texture(texture)
        {
            _frame.width = _texture.width / _frameMatrix.x;
            _frame.height = _texture.height / _frameMatrix.y;
        }
        void setName(string name)
        {
            _name = name;
        }
        void setFrameMatrix(Vector2 frameMatrix)
        {
            _frameMatrix = frameMatrix;
        }
        void setTexture(Texture2D texture)
        {
            _texture = texture;
        }
        string getName()
        {
            return _name;
        }
        Vector2 getFrameMatrix()
        {
            return _frameMatrix;
        }
        Texture2D getTexture()
        {
            return _texture;
        }
        Rectangle getFrame()
        {
            return _frame;
        }
};

class mesh
{
    private:
        string _name;
        Vector2 _position;
        map<string, myTexture> _textures;
    public:
        mesh(string name, Vector2 position)
        {
            _name = name;
            _position = position;
        }
        void addTexture(string name, Vector2 frameMatrix, Texture2D texture)
        {
            _textures[name] = myTexture(name, frameMatrix, texture);
        }
        void removeTexture(string name)
        {
            _textures.erase(name);
        }
        void setPosition(Vector2 position)
        {
            _position = position;
        }
        void setName(string name)
        {
            _name = name;
        }
        Vector2 getPosition()
        {
            return _position;
        }
        string getName()
        {
            return _name;
        }
        map<string, myTexture> getTextures()
        {
            return _textures;
        }
        void drawRec(const string& key)
        {
            DrawTextureRec(_textures[key].getTexture(), _textures[key].getFrame(), _position, WHITE);
        
        }
};

class player : public mesh
{
    private:
        int _health;
        int _attack;
        int _speed;
        int _level;
    public:
        player(string name, Vector2 position, int health, int attack, int speed, int level) : mesh(name, position)
        {
            _health = health;
            _attack = attack;
            _speed = speed;
            _level = level;
        }
        void setHealth(int health)
        {
            _health = health;
        }
        void setAttack(int attack)
        {
            _attack = attack;
        }
        void setSpeed(int speed)
        {
            _speed = speed;
        }
        void setLevel(int level)
        {
            _level = level;
        }
        int getHealth()
        {
            return _health;
        }
        int getAttack()
        {
            return _attack;
        }
        int getSpeed()
        {
            return _speed;
        }
        int getLevel()
        {
            return _level;
        }
};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "csgo");

    player player("player", (Vector2){ 400, 280 }, 100, 10, 1, 1);



    // SET TEXTURES

    player.addTexture("walkR", (Vector2){6, 1}, LoadTexture("sprites/characters/walkR.png")); // 1 ,6 here is the row and column count of frames in the spritesheet
    // player.addTexture("walkL", (Vector2){6, 1}, LoadTexture("sprites/characters/walkL.png"));
    player.addTexture("walkU", (Vector2){6, 1}, LoadTexture("sprites/characters/walkU.png"));
    player.addTexture("walkD", (Vector2){6, 1}, LoadTexture("sprites/characters/walkD.png"));





    // CAMERA
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.getPosition().x, player.getPosition().y};
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;




    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    while(!WindowShouldClose())
    {
        BeginDrawing();
            BeginMode2D(camera);
                ClearBackground(RAYWHITE);
                DrawCircle(400, 280, 5.0F, RED);
                player.drawRec("walkR");
                player.setPosition((Vector2){player.getPosition().x + 1, player.getPosition().y});
                camera.target = player.getPosition();
            EndMode2D();
        EndDrawing();
    }
}

/*
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
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

    t_player player;

    //-------------------------------------------------------------------------------------
    //SET IMAGES
    //-------------------------------------------------------------------------------------
    Image character[6];   // Load image in CPU memory (RAM)
    Image walk[6];
    Image up[6];
    Image down[6];
    Image rw[6];
    Image fencetek = LoadImage("assets/fences/fencesingle.png");
    Image slime[6];
    Image attack[4];
    Image floor = LoadImage("assets/grass.png");   // Load image in CPU memory (RAM)
    fillImages(character, walk, up, down, rw, slime, attack);
    //-------------------------------------------------------------------------------------


    //-------------------------------------------------------------------------------------
    //SET TEXTURES
    //-------------------------------------------------------------------------------------
    Texture2D img_tex = LoadTextureFromImage(character[0]);
    Texture2D img_tex2 = LoadTextureFromImage(floor);
    Texture2D ft = LoadTextureFromImage(fencetek);
    Texture2D slm;
    Texture2D atck;
    //-------------------------------------------------------------------------------------

    Rectangle playerArea = { player.position.x, player.position.y, 40, 40};
    int slc = 0;
    ft.width = 40;
    ft.height = 40;
    img_tex.width = 40;
    img_tex.height = 40;
    img_tex2.width = 40;
    img_tex2.height = 45;
    player.texture = img_tex;
    player.position = (Vector2){ 400, 280 };

    //-------------------------------------------------------------------------------------
    //SET CAMERA
    //-------------------------------------------------------------------------------------
    int spacing = 0;
    Camera2D camera = { 0 };
    camera.target = (Vector2){ player.position.x + 20.0f, player.position.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    //-------------------------------------------------------------------------------------

    Vector2 randomFence[20];
    for (int i = 0; i < 20; ++i)
    {
        randomFence[i].x =  GetRandomValue(200,700) + i*20;
        randomFence[i].y =  GetRandomValue(100,600) + i*20;
    }


    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------
        // Player movement
        UnloadTexture(img_tex);
        if (IsKeyDown(KEY_RIGHT))
        {
            if (CheckCollisionRecs(playerArea, (Rectangle){ 470, 300, 32, 32 }) == 0)
                player.position.x += 2;
            rightSprite(img_tex, wlk, walk);
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            leftSprite(img_tex, r, rw);
            player.position.x -= 2;
        }
        else if (IsKeyDown(KEY_UP))
        {
            downSprite(img_tex, u, up);
            player.position.y -= 2;
        }
        else if (IsKeyDown(KEY_DOWN))
        {
            upSprite(img_tex, d, down);
            player.position.y += 2;
        }
        else if (IsKeyDown(KEY_SPACE))
            attackSprite(img_tex, at, attack);
        else
        {
            defaultSprite(img_tex, spt, character);
            at = 0;
        }
        slimeSprite(slm, slc, slime);
        playerArea.x = player.position.x;
        playerArea.y = player.position.y;
        // Camera target follows player
        camera.target = (Vector2){ player.position.x + 20, player.position.y + 20 };

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
                    DrawTexture(img_tex2, i*40, j*45, WHITE);
            BeginMode2D(camera);
                DrawTexture(img_tex, player.position.x,player.position.y, WHITE);
                spd++;
                for (int i = 0; i < 20; ++i)
                {
                    DrawTexture(ft, randomFence[i].x, randomFence[i].y, WHITE);
                }
                DrawTexture(slm, 350, 420, WHITE);
                DrawTexture(slm, 170, 60, WHITE);
                DrawTexture(slm, 250, 700, WHITE);
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
    UnloadTexture(img_tex);       // Texture unloading
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
*/