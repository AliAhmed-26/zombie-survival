#include "Bullet.h"
#include "raymath.h"

Bullet::Bullet(Vector2 start, Vector2 target, float speed, int damage, float radius)
    : position(start),
      direction({0.0f, 0.0f}),
      speed(speed),
      radius(radius),
      damage(damage),
      active(true)
{
    Vector2 diff = Vector2Subtract(target, start);
    if (Vector2Length(diff) == 0.0f)
    {
        active = false;                   // no direction, so the bullet is useless
    }
    else
    {
        direction = Vector2Normalize(diff);
    }
}

void Bullet::Update(float deltaTime)
{
    if (!active) return;

    position = Vector2Add(position, Vector2Scale(direction, speed * deltaTime));

    if (IsOffScreen()) Deactivate();
}

void Bullet::Draw() const
{
    if (active) DrawCircleV(position, radius, YELLOW);
}

bool Bullet::IsActive() const { return active; }
void Bullet::Deactivate() { active = false; }

bool Bullet::IsOffScreen() const
{
    return position.x < 0 || position.x > GetScreenWidth() ||
           position.y < 0 || position.y > GetScreenHeight();
}

Vector2 Bullet::GetPosition() const { return position; }
float Bullet::GetRadius() const { return radius; }
int Bullet::GetDamage() const { return damage; }