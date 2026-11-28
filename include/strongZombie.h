#pragma once
#include "Zombie.h"
#include "raylib.h"

class StrongZombie : public Zombie
{
public:
    StrongZombie(Vector2 position_arg);
    void load();
    void unload();
    void draw() const override;
};