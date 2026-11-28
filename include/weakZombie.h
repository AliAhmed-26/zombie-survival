#pragma once
#include "Zombie.h"
#include "raylib.h"

class WeakZombie : public Zombie
{
public:
    WeakZombie(Vector2 position_arg);
    void load();
    void unload();
    void draw() const override;
};