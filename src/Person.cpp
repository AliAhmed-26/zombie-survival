#include "../include/Person.h"

// Constructor: sets all starting values. Health starts at max.
Person::Person(Vector2 position_arg, float speed_arg, Color color_arg, unsigned int maxHealth_arg) : position{position_arg}, health{maxHealth_arg}, maxHealth{maxHealth_arg}, speed{speed_arg}, color{color_arg}
{
}

// ---------- Setters ----------

// Set a new position
void Person::setPosition(Vector2 position_arg)
{
    position = position_arg;
}

// Set health, but never above maxHealth
void Person::setHealth(unsigned int health_arg)
{
    if (health_arg >= maxHealth)
    {
        health = maxHealth;
    }
    else
    {
        health = health_arg;
    }
}

// Set speed
void Person::setSpeed(float speed_arg)
{
    speed = speed_arg;
}

// Set color
void Person::setColor(Color color_arg)
{
    color = color_arg;
}

// ---------- Getters ----------

// Get position
Vector2 Person::getPosition() const
{
    return position;
}

// Get current health
unsigned int Person::getHealth() const
{
    return health;
}

// Get max health
unsigned int Person::getMaxHealth() const
{
    return maxHealth;
}

// Get speed
float Person::getSpeed() const
{
    return speed;
}

// Get color
Color Person::getColor() const
{
    return color;
}

// ---------- Game logic ----------

// Alive if health is more than 0
bool Person::isAlive() const
{
    return (health > 0);
}

// Reduce health by damage amount
void Person::takeDamage(unsigned int damage_arg)
{
    // Already dead, do nothing
    if (!isAlive())
    {
        return;
    }

    if (damage_arg >= health)
    {
        // Damage is too big: set health to 0 (unsigned would wrap around if we subtracted)
        health = 0;
    }
    else
    {
        health -= damage_arg;
    }
}

// Checks if the person can move to the new spot
// newbounds = the box where the person wants to go
// obstacles = list of walls/objects
bool Person::canMoveTo(Rectangle nextPosition, const std::vector<Rectangle> &obstacles) const
{
    // Check every obstacle
    for (const Rectangle &obstacle : obstacles)
    {
        // If the new box hits an obstacle, movement is not allowed
        if (CheckCollisionRecs(nextPosition, obstacle))
        {
            return false;
        }
    }

    // No collisions, movement is allowed
    return true;
}