#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

//  One bullet flying across the screen. It moves in a straight
//  line, can be drawn, and knows how much damage it deals.

class Bullet
{
private:
    Vector2 position;   // current position
    Vector2 direction;  // unit vector (length 1) showing where it flies
    float speed;        // pixels per second
    float radius;       // size of the bullet (used for drawing + collision)
    int damage;         // damage dealt to a zombie on hit
    bool active;        // false = bullet is finished and should be removed

public:
    // 'target' is where the player is aiming (mouse position).
    // The constructor calculates the direction from start -> target.
    Bullet(Vector2 start, Vector2 target, float speed, int damage, float radius = 4.0f);

    // Game loop functions
    void Update(float deltaTime);   // move the bullet; deactivate if off-screen
    void Draw() const;              // draw the bullet with raylib

    // State 
    bool IsActive() const;
    void Deactivate();              // call this when it hits a zombie
    bool IsOffScreen() const;       // outside the game window?

    // Getters (used for collision checks in Game)
    Vector2 GetPosition() const;
    float GetRadius() const;
    int GetDamage() const;
};

#endif // BULLET_H