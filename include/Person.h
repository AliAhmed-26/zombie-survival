#pragma once
#include "raylib.h"
#include <vector>

// Base class for anything that moves in the game (Player, enemies, etc.)
class Person
{
protected:
    Vector2 position;
    unsigned int health, maxHealth;
    float speed;
    Color color;

public:
    // Constructor. maxHealth_arg defaults to 100 if you don't pass it
    Person(Vector2 position_arg, float speed_arg, Color color_arg, unsigned int maxHealth_arg = 100);

    // ---------- Setters ----------
    void setPosition(Vector2 position_arg);
    void setHealth(unsigned int health_arg);
    void setSpeed(float speed_arg);
    void setColor(Color color_arg);

    // ---------- Getters ----------
    Vector2 getPosition() const;
    unsigned int getHealth() const;
    unsigned int getMaxHealth() const;
    float getSpeed() const;
    Color getColor() const;

    // Reduce health by the damage amount
    void takeDamage(unsigned int damage_arg);

    // True if health is more than 0
    bool isAlive() const;

    // True if the person can move into newBounds without hitting any obstacle
    bool canMoveTo(
        Rectangle nextPosition,
        const std::vector<Rectangle> &obstacles) const;

    virtual void move(float dt,const std::vector<Rectangle> &obstacles) = 0;
    virtual void draw() const = 0;

    virtual ~Person() = default;
};