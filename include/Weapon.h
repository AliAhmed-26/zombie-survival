#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
#include "raylib.h"
#include "Ammo.h"
#include "Bullet.h"

//  The weapon owns an Ammo object and creates Bullet objects.
//  It controls fire rate (cooldown) and reloading (timer).
//
//  How Member 4 (Game) will use it every frame:
//      weapon.Update(deltaTime);
//      if (left mouse pressed)  weapon.Fire(playerPos, mousePos, bullets);
//      if (R pressed)           weapon.StartReload();

class Weapon
{
private:
    Texture2D texture;
    std::string name;  // e.g. "Pistol"
    int damage;        // damage of each bullet
    float fireRate;    // shots per second (e.g. 3.0 = 3 shots/sec)
    float bulletSpeed; // speed given to every bullet it creates
    float reloadTime;  // seconds a reload takes

    Ammo ammo; // composition: a Weapon HAS an Ammo

    float fireCooldown; // time left before the next shot is allowed
    bool reloading;     // true while a reload is in progress
    float reloadTimer;  // time spent reloading so far

public:
    Weapon(const std::string &name = "Pistol",
           int damage = 25,
           float fireRate = 3.0f,
           float bulletSpeed = 600.0f,
           float reloadTime = 1.5f,
           int magazineSize = 12,
           int maxReserve = 60);

    // Game loop
    void Load();
    void Unload();
    void Draw(Vector2 player_position, float rotation) const;
    void Update(float deltaTime); // updates cooldown + reload timer

    // Shooting
    // Tries to shoot. If allowed, creates a Bullet, adds it to 'bullets'
    // and returns true. Returns false if reloading, on cooldown or empty.
    bool Fire(Vector2 origin, Vector2 target, std::vector<Bullet> &bullets);
    bool CanFire() const;

    // Reloading
    void StartReload(); // begins reload (if possible)
    bool IsReloading() const;
    float GetReloadProgress() const; // 0.0 to 1.0 (for a UI reload bar)

    // Pickups / reset
    void AddAmmo(int amount); // pick up spare bullets
    void Reset();             // for game restart

    // Getters (used by Member 4's UI)
    const std::string &GetName() const;
    int GetDamage() const;
    const Ammo &GetAmmo() const;
};

#endif // WEAPON_H