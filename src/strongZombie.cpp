
#include "raylib.h"
#include "strongZombie.h"

class strongZombie : public Zombie
{
    public:
        strongZombie(Vector2 position_arg)
         : Zombie(position_arg,
                  1.0f,             //Speed
                  RED,              //Color
                  45.0f,            //Width
                  45.0f,            //Height
                  150,              //Health
                  20                //Attack
                 )
        {}
};