#include <iostream>  
#include "raylib.h" 
#include "Grid.h"

using namespace std;
int main(void)
{
    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "bomsdika");

    SetTargetFPS(60);               
    Grid grid = Grid();
   
 

    // Main game loop
    while (!WindowShouldClose())    
    {

        BeginDrawing();

        ClearBackground(BLACK);

        grid.Draw();

        EndDrawing();
      
    }

    // De-Initialization

    CloseWindow();        

    return 0;
}