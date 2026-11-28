
#include "raylib.h"
#include "strongZombie.h"

strongZombie::strongZombie(Vector2 position_arg)
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

void strongZombie::load()
{
    texture = LoadTexture("assets/enemy/strong_zombie.png");
}

void strongZombie::unload()
{
    UnloadTexture(texture);
}

void strongZombie::draw() const
{
    DrawTexture(texture, position.x, position.y, WHITE);
}