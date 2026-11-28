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
        active = false; // no direction, so the bullet is useless
    }
    else
    {
        direction = Vector2Normalize(diff);
    }
    texture = LoadTexture("assets/bullet/bullet.png");
}

void Bullet::Load()
{
}

void Bullet::Unload()
{
    UnloadTexture(texture);
}

void Bullet::Update(float deltaTime)
{
    if (!active)
        return;

    position = Vector2Add(position, Vector2Scale(direction, speed * deltaTime));

    if (IsOffScreen())
        Deactivate();
}

void Bullet::Draw() const
{
    if (!active)
        return;

    // direction se goli ka angle (degrees)
    float angle = atan2f(direction.y, direction.x) * RAD2DEG+45.0f;

    Rectangle src = {0, 0, (float)texture.width, (float)texture.height};
    Rectangle dst = {
        position.x,
        position.y,
        radius * 2,
        radius * 2};
    Vector2 origin = {dst.width / 2, dst.height / 2}; 

    DrawTexturePro(texture, src, dst, origin, angle, WHITE);
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