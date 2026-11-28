#include "raylib.h"
#include "weakZombie.h"

weakZombie::weakZombie(Vector2 position_arg)
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

void weakZombie::load()
{
    texture = LoadTexture("assets/enemy/weak_zombie.png");
}

void weakZombie::unload()
{
    UnloadTexture(texture);
}

void weakZombie::draw() const
{
    DrawTexture(texture, position.x, position.y, WHITE);
}