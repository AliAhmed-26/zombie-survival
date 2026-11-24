#pragma once
#include "raylib.h"
#include "Enemy.h"
#include "Player.h"

class Zombie : public Enemy
{
protected:
    Texture2D texture;

public:
    Zombie(Vector2 position_arg,
           float speed_arg,
           Color color_arg,
           float width_arg,
           float height_arg,
           unsigned int maxHealth_arg,
           unsigned int damage_arg);

    void attack(Player &player); // When zombie attacks player
};