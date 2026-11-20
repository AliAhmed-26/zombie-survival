#pragma once
#include "../include/Person.h"
#include "raylib.h"

class Enemy : public Person
{
private:
    float width;
    float height;

public:
    Enemy(
        Vector2 position_arg,
        float speed_arg,
        Color color_arg,
        float width_arg,
        float height_arg,
        unsigned int maxHealth_arg = 100
    );

    // SET WIDTH AND HEIGHT
    void setWidth(float w);
    void setHeight(float h);

    float getWidth() const;
    float getHeight() const;

    // MOVE ENEMY TOWARDS PLAYER
    void followPlayer(Vector2 playerPosition, float dt);

    // KEEP ENEMY INSIDE GAME WINDOW
    void checkBoundary();

    // RETURN ENEMY RECTANGLE FOR COLLISION
    Rectangle getBounds() const;

    void move(float dt) override;
    void draw() const override;
};
