#include "raylib.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // yeh InitWindow se PEHLE
    InitWindow(1672, 941, "Zombie Survival");
    MaximizeWindow();
    SetTargetFPS(60);

    {
        Game game(

            // Player
            {1500, 400},
            200.0f,
            WHITE,
            110.0f,
            110.0f,
            100,

            // Weapon
            "Pistol",
            25,
            60.0f,
            600.0f,
            1.0f,
            12,
            60);

        game.play();
    }

    CloseWindow();

    return 0;
}