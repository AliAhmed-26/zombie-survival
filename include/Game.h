#include "Map.h"
#include "Player.h"
#include "weakZombie.h"
#include "strongZombie.h"
#include "Weapon.h"
#include "Ammo.h"
#include "Bullet.h"

class Game
{
private:
    Map map;
    Player player;
    std::vector<WeakZombie> weakZombies;
    std::vector<StrongZombie> strongZombies;

    Weapon weapon;
    std::vector<Bullet> bullets;

public:
    Game(
         // player
         Vector2 position_player, float speed_player, Color color_player, float width_player, float height_player, unsigned int maxHealth_player = 100,
         // weapon
         const std::string &name_weapon = "Pistol", int damage_weapon = 25, float fireRate_weapon = 3.0f, float bulletSpeed_weapon = 600.0f, float reloadTime_weapon = 1.5f, int magazineSize_weapon = 12, int maxReserve_weapon = 60);

    void play();
};
