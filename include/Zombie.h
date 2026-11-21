#pragma once 
#include "raylib.h"
#include "Enemy.h"

class Zombie : public Enemy
{
    protected:
        unsigned int damage;

    public:
        Zombie(Vector2 position_arg,
        float speed_arg,
        Color color_arg,
        float width_arg,
        float height_arg,
        unsigned int maxHealth_arg,
        unsigned int damage_arg);

        void attack();      //When zombie attacks player

   
};
