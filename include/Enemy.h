#pragma once
#include "../include/Person.h"
#include "raylib.h"

class Enemy : public Person
{
protected:
    float width;
    float height;
    unsigned int damage;
    Vector2 movementDirection{0, 0};

public:
    Enemy(
        Vector2 position_arg,
        float speed_arg,
        Color color_arg,
        float width_arg,
        float height_arg,
        unsigned int maxHealth_arg,
        unsigned int damage_arg
    );

    // Setter Functions
    void setWidth(float w);
    void setHeight(float h);

    //Getter Functions
    float getWidth() const;
    float getHeight() const;

    //To move enemy towards player
    void followPlayer(Vector2 playerPosition, float dt);

    // To check that zombie are in window or not
    void checkBoundary();

    // Gives enemy rectangle for the collision detection
    Rectangle getBounds() const;

    void move(float dt, const std::vector<Rectangle> &obstacles) override;
};
