#pragma once
#include "Zombie.h"
#include "raylib.h"

class strongZombie : public Zombie
{
public:
    strongZombie(Vector2 position_arg);
    void load();
    void unload();
    void draw() const override;
};