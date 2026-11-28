#include "raylib.h"
#include "WeakZombie.h"
#include <iostream>

WeakZombie::WeakZombie(Vector2 position_arg)
    : Zombie(position_arg,
             30.0f,   // Speed
             GREEN,  // Color
             130.0f, // Width
             130.0f, // Height
             50,     // Health
             5       // Attack
      )
{
    texture = LoadTexture("assets/enemy/weak_zombie.png");
}

void WeakZombie::load()
{
}

void WeakZombie::unload()
{
    UnloadTexture(texture);
}

void WeakZombie::draw() const
{
    DrawTexturePro(
        texture,
        {0, 0, (float)texture.width, (float)texture.height},
        {position.x,
         position.y,
         width,
         height},
        {0, 0},
        0.0f,
        WHITE);
}