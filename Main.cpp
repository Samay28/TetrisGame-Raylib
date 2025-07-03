#include <iostream>  
#include "raylib.h" 
#include <ctime>
#include "GameManager.h"
#include "ColorDatabase.h"

using namespace std;

double lastUpdatedTime = 0;
bool eventTriggered(double Interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdatedTime >= Interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

int main(void)
{
    const int screenWidth = 500;
    const int screenHeight = 620;
    

    InitWindow(screenWidth, screenHeight, "bomsdika");

    SetTargetFPS(60);               
    srand(time(0)); //for setting different seed for random generator

    Font font = LoadFontEx("Font/Dream Head.otf", 64, 0, 0);
    
    GameManager gm = GameManager();

    // Main game loop
    while (!WindowShouldClose())    
    {   
        UpdateMusicStream(gm.music);
        if (eventTriggered(0.2)) // to be called after every 200ms
        {
            gm.MoveBlockDown();
           
        }

        BeginDrawing();

        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);

        DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);
        if (gm.GameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320,450 }, 38, 2, WHITE);
        }


        DrawRectangleRounded({ 320,55,170,60 }, 0.3, 6, lightBlue);
        char scoreTxt[10]; //draw score text implmenetation 
        sprintf_s(scoreTxt, sizeof(scoreTxt), "%d", gm.getScore()); //converted to int
        Vector2 textSize = MeasureTextEx(font,scoreTxt,38,2);
        DrawTextEx(font, scoreTxt, { 320 + (170 - textSize.x)/2,65 }, 38, 2, WHITE); //170 is width of rect, doing this to anchor it at centre always
       
        
        DrawRectangleRounded({ 320,215,170,180 }, 0.3, 6, lightBlue);


        gm.HandleInput();

        gm.Draw();

        EndDrawing();
      
    }

    // De-Initialization

    CloseWindow();        

    return 0;
}