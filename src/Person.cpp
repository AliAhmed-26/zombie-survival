#include "Person.h"

Person::Person(Vector2 position_arg, unsigned int maxHealth_arg, float speed_arg, Color color_arg) : position{position_arg}, health{maxHealth_arg}, maxHealth{maxHealth_arg}, speed{speed_arg}, color{color_arg}
{
}

void Person::setPosition(Vector2 position_arg)
{
    position = position_arg;
}

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

void Person::setSpeed(float speed_arg)
{
    speed = speed_arg;
}

void Person::setColor(Color color_arg)
{
    color = color_arg;
}

Vector2 Person::getPosition() const
{
    return position;
}
unsigned int Person::getHealth() const
{
    return health;
}
unsigned int Person::getMaxHealth() const
{
    return maxHealth;
}
float Person::getSpeed() const
{
    return speed;
}
Color Person::getColor() const
{
    return color;
}

bool Person::isAlive() const
{
    return (health > 0);
}

void Person::takeDamage(unsigned int damage_arg)
{
    if (!isAlive())
    {
        return;
    }
    if (damage_arg >= health)
    {
        health = 0;
    }
    else
    {
        health -= damage_arg;
    }
}