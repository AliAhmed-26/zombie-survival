#include "Enemy.h"
#include <cmath>


    Enemy::Enemy(
        Vector2 position_arg,
        float speed_arg,
        Color color_arg,
        float width_arg,
        float height_arg,
        unsigned int maxHealth_arg,
        unsigned int damage_arg) : Person(position_arg, speed_arg, color_arg, maxHealth_arg), width(width_arg), height(height_arg), damage(damage_arg)
    {
    }

    // SET WIDTH AND HEIGHT
    void Enemy::setWidth(float w)
    {
        if (w >= 0 && w <= 800)
        {
            width = w;
        }
    }
    void Enemy::setHeight(float h)
    {
        if (h >= 0 && h <= 600)
        {
            height = h;
        }
    }

    // GET WIDTH AND HEIGHT
    float Enemy::getWidth() const
    {
        return width;
    }
    float Enemy::getHeight() const
    {
        return height;
    }

    // MOVE ENEMY TOWARDS PLAYER
    void Enemy::followPlayer(Vector2 playerPosition, float dt)
    {
        float dx = playerPosition.x - position.x;
        float dy = playerPosition.y - position.y;

        float distance = sqrtf(dx * dx + dy * dy);

        if (distance > 0.0f)
        {
            movementDirection.x = dx / distance;
            movementDirection.y = dy / distance;
        }
        else
        {
            movementDirection = {0, 0};
        }
    }

    // KEEP ENEMY INSIDE GAME WINDOW
    void Enemy::checkBoundary()
    {
        {
            if (position.x < 0)
            {
                position.x = 0;
            }

            if (position.y < 0)
            {
                position.y = 0;
            }

            if (position.x + width > GetScreenWidth())
            {
                position.x = GetScreenWidth() - width;
            }

            if (position.y + height > GetScreenHeight())
            {
                position.y = GetScreenHeight() - height;
            }
        }
    }

    // RETURN ENEMY RECTANGLE FOR COLLISION
    Rectangle Enemy::getBounds() const
    {
        return {position.x, position.y, width, height};
    }

    void Enemy::move(float dt, const std::vector<Rectangle> &obstacles)
    {
        float moveX = movementDirection.x * speed * dt;
        float moveY = movementDirection.y * speed * dt;

        // Try moving horizontally
        Rectangle nextBounds = getBounds();
        nextBounds.x += moveX;

        if (canMoveTo(nextBounds, obstacles))
        {
            position.x += moveX;
        }

        // Try moving vertically
        nextBounds = getBounds();
        nextBounds.y += moveY;

        if (canMoveTo(nextBounds, obstacles))
        {
            position.y += moveY;
        }

        checkBoundary();
    }

    void Enemy::draw() const
    {
        DrawRectangleRec(getBounds(), color);
    }
