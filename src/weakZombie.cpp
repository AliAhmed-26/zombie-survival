#include "raylib.h"
#include "WeakZombie.h"

WeakZombie::WeakZombie(Vector2 position_arg)
    : Zombie(position_arg,
             2.0f,  // Speed
             GREEN, // Color
             25.0f, // Width
             25.0f, // Height
             50,    // Health
             5      // Attack
      )
{
}

void WeakZombie::load()
{
    texture = LoadTexture("assets/enemy/weak_zombie.png");
}

void WeakZombie::unload()
{
    UnloadTexture(texture);
}

void WeakZombie::draw() const
{
    DrawTexture(texture, position.x, position.y, WHITE);
}