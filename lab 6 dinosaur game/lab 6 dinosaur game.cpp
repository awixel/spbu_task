#include <raylib.h>// для работы необходимо установить raylib из nuget
#include <iostream> 
#include <random>
using namespace std;
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(0, 10000);
int random()
{
    return distrib(gen);
}
enum Type { ARROW, HEART, NONE };
class Object
{
public:
    Texture2D texture;
    Rectangle hitbox;
    Color color = WHITE;
    Type type;
    float x, x0, y, y0, height, width;
    int spawnchance = 100, speed = 30, flag = 0, buff = 0;
    Object() = default;
    Object(float x, float y, float height, float width, Texture2D texture, int speed, Type type, int spawnchance) :
        texture{ texture }, x{ x }, x0{ x }, y{ y }, y0{ y }, height{ height }, width{ width }, speed{ speed }, type{ type }, spawnchance{ spawnchance } {
    }
    friend void spawnObject(Object& thing, Object& dino, Object& cactus)
    {
        if (random() < thing.spawnchance)
        {
            thing.flag = 1;
        }
        if (thing.flag == 1)
        {
            thing.x -= thing.speed;
        }
        if (thing.x < -300)
        {
            thing.x = thing.x0;
            thing.flag = 0;
        }
        if (CheckCollisionRecs(dino.hitbox, thing.hitbox))
        {
            if (thing.type == HEART)
            {
                dino.buff = 1;
                dino.color = MAGENTA;
            }
            if (thing.type == ARROW)
            {

                cactus.speed -= 10;
            }
            thing.x = thing.x0;
            thing.flag = 0;
        }
    }
};
int main()
{
    InitWindow(2560, 1440, " dinozavrik ");
    SetTargetFPS(60);
    bool gamestatus = true;
    int  score = 0;
    Object heart(3000, 400, 125, 125, LoadTexture("C:/Users/antos/OneDrive/Desktop/для игры/сердце.png"), 30, HEART, 9);
    Object arrow(3000, 400, 125, 125, LoadTexture("C:/Users/antos/OneDrive/Desktop/для игры/стрелка.png"), 30, ARROW, 10);
    Object dino(200, 710, 250, 230, LoadTexture("C:/Users/antos/OneDrive/Desktop/для игры/dino.png"), 0, NONE, 0);
    Object cactus(2950, 825, 175, 100, LoadTexture("C:/Users/antos/OneDrive/Desktop/для игры/кактус.png"), 20, NONE, 0);
    Object cloud(2900, 150, 125, 125, LoadTexture("C:/Users/antos/OneDrive/Desktop/для игры/облако.png"), 3, NONE, 50);
    while (!WindowShouldClose())
    {
        if (gamestatus == true)
        {
            score++;
            cloud.speed = cactus.speed - 19;
            if (IsKeyPressed(KEY_UP) and dino.y >= dino.y0)
            {
                dino.flag = 1;
            }
            if (dino.flag == 1 and dino.y >= 225)
            {
                dino.y -= 40;
            }
            else dino.flag = 0;
            if (dino.y <= dino.y0 and dino.flag == 0)
            {
                dino.y += 20;
            }
            cactus.x -= cactus.speed;
            dino.hitbox = { dino.x + 10, dino.y + 25, dino.width, dino.height };
            cactus.hitbox = { cactus.x, cactus.y, cactus.width, cactus.height };
            heart.hitbox = { heart.x, heart.y + 25, 125, 125 };
            arrow.hitbox = { arrow.x, arrow.y + 25, 125, 125 };
            if (cactus.x < -200)
            {
                cactus.x = 3000;
            }
            if (score % 150 == 0 and cactus.speed < 80)
            {
                cactus.speed += 1;
            }
            if (CheckCollisionRecs(dino.hitbox, cactus.hitbox))
            {
                if (dino.buff == 0)
                {
                    gamestatus = false;
                    dino.buff = 0;
                    while (!IsKeyPressed(KEY_R))
                    {
                        BeginDrawing();
                        DrawText("GAME OVER", 1000, 140, 50, RED);
                        DrawText(TextFormat("Score: %d", score), 1000, 100, 50, WHITE);
                        DrawText("PRESS R TO RESTART", 900, 220, 50, RED);
                        DrawText(TextFormat("Speed: %d", cactus.speed), 600, 100, 50, WHITE);
                        ClearBackground(SKYBLUE);
                        DrawRectangle(dino.x - 200, 1000, 4000, 1000, DARKGREEN);
                        DrawTextureEx(dino.texture, { dino.x, dino.y + 25 }, 0, 0.2, dino.color);
                        DrawTextureEx(cactus.texture, { cactus.x - 25, cactus.y - 20 }, 0, 0.25, WHITE);
                        DrawTextureEx(heart.texture, { heart.x, heart.y + 25 }, 0, 0.5, WHITE);
                        DrawTextureEx(arrow.texture, { arrow.x, arrow.y + 25 }, 0, 0.25, WHITE);
                        DrawTextureEx(heart.texture, { 50, 50 }, 0, 0.5, BLACK);
                        DrawTextureEx(cloud.texture, { cloud.x, cloud.y }, 0, 0.5, Fade(WHITE, 0.5f));
                        /*DrawRectangleLines(dino.x + 10, dino.y + 25, dino.width, dino.height, RED);
                        DrawRectangleLines(cactus.x, cactus.y, cactus.width, cactus.height, RED);
                        DrawRectangleLines(heart.x, heart.y + 25, 125, 125, RED); проверка хитбокса*/
                        EndDrawing();
                    }
                    gamestatus = true;
                    cactus.x = cactus.x0;
                    score = 0;
                    cactus.speed = 20;
                    cloud.x = cloud.x0;
                    heart.x = heart.x0;
                    arrow.x = arrow.x0;
                }
                if (dino.buff == 1)
                {
                    cactus.flag = 1;
                }
            }
            if (cactus.flag == 1 and cactus.x + cactus.width < dino.x)
            {
                dino.color = WHITE;
                dino.buff = 0;
                cactus.flag = 0;
            }
            if (cactus.speed > 40) spawnObject(arrow, dino, cactus);
            spawnObject(heart, dino, cactus);
            spawnObject(cloud, dino, cactus);
            BeginDrawing();
            DrawText(TextFormat("Score: %d", score), 1000, 100, 50, WHITE);
            DrawText(TextFormat("Speed: %d", cactus.speed), 600, 100, 50, WHITE);
            ClearBackground(SKYBLUE);
            DrawRectangle(dino.x - 200, 1000, 4000, 1000, DARKGREEN);
            DrawTextureEx(dino.texture, { dino.x, dino.y + 25 }, 0, 0.2, dino.color);
            DrawTextureEx(cactus.texture, { cactus.x - 25, cactus.y - 20 }, 0, 0.25, WHITE);
            DrawTextureEx(heart.texture, { heart.x, heart.y + 25 }, 0, 0.5, WHITE);
            DrawTextureEx(arrow.texture, { arrow.x, arrow.y + 25 }, 0, 0.25, WHITE);
            DrawTextureEx(cloud.texture, { cloud.x, cloud.y }, 0, 0.5, Fade(WHITE, 0.75f));
            if (dino.buff == 1)
            {
                DrawTextureEx(heart.texture, { 50, 50 }, 0, 0.5, WHITE);
            }
            else
            {
                DrawTextureEx(heart.texture, { 50, 50 }, 0, 0.5, BLACK);
            }
            /*DrawRectangleLines(dino.x + 10, dino.y + 25, dino.width, dino.height, RED);
            DrawRectangleLines(cactus.x, cactus.y, cactus.width, cactus.height, RED);
            DrawRectangleLines(heart.x, heart.y + 25, 125, 125, RED); проверка хитбокса
            DrawRectangleLines(arrow.x, arrow.y + 25, 125, 125, RED);*/
            EndDrawing();
        }
    }
}