#include "Zombie.h"
#include "Player.h"

Zombie::Zombie(Vector2 position_arg,
               float speed_arg,
               Color color_arg,
               float width_arg,
               float height_arg,
               unsigned int maxHealth_arg,
               unsigned int damage_arg)
    : Enemy(position_arg, speed_arg, color_arg, width_arg, height_arg, maxHealth_arg, damage_arg), texture{0}
{
}

void Zombie::attack(Player &player) // When zombie attacks player
{
    {
        if (!isAlive() || !player.isAlive())
            return;

        if (CheckCollisionRecs(getBounds(), player.getBounds()))
        {
            player.takeDamage(damage);
        }
    }
}