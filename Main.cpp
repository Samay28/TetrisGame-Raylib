#include <iostream>  
#include "raylib.h" 
#include <ctime>
#include "GameManager.h"


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
    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "bomsdika");

    SetTargetFPS(60);               
    srand(time(0)); //for setting different seed for random generator
    
    GameManager gm = GameManager();

    // Main game loop
    while (!WindowShouldClose())    
    {   

        if (eventTriggered(0.2)) // to be called after every 200ms
        {
            gm.MoveBlockDown();
        }

        BeginDrawing();

        ClearBackground(BLACK);
        gm.HandleInput();

        gm.Draw();

        EndDrawing();
      
    }

    // De-Initialization

    CloseWindow();        

    return 0;
}