
#include "raylib.h"
#include "StrongZombie.h"

StrongZombie::StrongZombie(Vector2 position_arg)
    : Zombie(position_arg,
             20.0f, // Speed
             RED,  // Color
             150.0f, // Width
             150.0f, // Height
             150,  // Health
             20    // Attack
      )
{
    texture = LoadTexture("assets/enemy/strong_zombie.png");
}

void StrongZombie::load()
{
}

void StrongZombie::unload()
{
    UnloadTexture(texture);
}

void StrongZombie::draw() const
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
