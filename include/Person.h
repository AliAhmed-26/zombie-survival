#pragma once
#include "raylib.h"
class Person
{
protected:
    Vector2 position;
    int health, maxHealth;
    float speed;
    Color color;

public:
    Person(Vector2 position_arg, int maxHealth_arg, float speed_arg, Color color_arg);

    void setPosition(Vector2 position_arg);
    void setHealth(int health_arg);
    void setSpeed(float speed_arg);
    void setColor(Color color_arg);

    Vector2 getPosition() const;
    int getHealth() const;
    int getMaxHealth() const;
    float getSpeed() const;
    Color getColor() const;

    bool isAlive() const;
    void takeDamage(int damage_arg);

    virtual void move(float dt) = 0;
    virtual void draw() const = 0;
    virtual ~Person() = default;
};
