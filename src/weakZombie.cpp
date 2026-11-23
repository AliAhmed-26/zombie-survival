#include "raylib.h"
#include "weakZombie.h"

class weakZombie : public Zombie
{
    public:
        weakZombie(Vector2 position_arg)
         : Zombie(position_arg,
                  2.0f,            //Speed
                  GREEN,           //Color
                  25.0f,           //Width
                  25.0f,           //Height
                  50,              //Health
                  5                //Attack
                 )
        {}
};