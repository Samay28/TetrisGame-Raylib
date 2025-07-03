#include <iostream>  
#include "raylib.h" 
#include "GameManager.h"


using namespace std;
int main(void)
{
    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "bomsdika");

    SetTargetFPS(60);               
    
    
    GameManager gm = GameManager();

    // Main game loop
    while (!WindowShouldClose())    
    {

        BeginDrawing();

        ClearBackground(BLACK);

        gm.Draw();

        EndDrawing();
      
    }

    // De-Initialization

    CloseWindow();        

    return 0;
}