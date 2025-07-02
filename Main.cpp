#include <iostream>  
#include "raylib.h" 
using namespace std;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "bomsdika");

    SetTargetFPS(60);               
 

    // Main game loop
    while (!WindowShouldClose())    
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("This is Bomsdika Window!!!", 200, 200, 20, LIGHTGRAY);

        EndDrawing();
      
    }

    // De-Initialization

    CloseWindow();        

    return 0;
}