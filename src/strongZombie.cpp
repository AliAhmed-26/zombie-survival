
#include "raylib.h"
#include "StrongZombie.h"

StrongZombie::StrongZombie(Vector2 position_arg)
    : Zombie(position_arg,
             1.0f,  // Speed
             RED,   // Color
             45.0f, // Width
             45.0f, // Height
             150,   // Health
             20     // Attack
      )
{
}

void StrongZombie::load()
{
    texture = LoadTexture("assets/enemy/strong_zombie.png");
}

void StrongZombie::unload()
{
    UnloadTexture(texture);
}

void StrongZombie::draw() const
{
    DrawTexture(texture, position.x, position.y, WHITE);
}