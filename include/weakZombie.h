#pragma once
#include "Zombie.h"
#include "raylib.h"

class weakZombie : public Zombie
{
public:
    weakZombie(Vector2 position_arg);
    void load();
    void unload();
    void draw() const override;
};