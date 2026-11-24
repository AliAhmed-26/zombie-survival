#include "Weapon.h"
#include "raymath.h"

Weapon::Weapon(const std::string& name, int damage, float fireRate,
               float bulletSpeed, float reloadTime,
               int magazineSize, int maxReserve)
    : name(name),
      damage(damage),
      fireRate(fireRate),
      bulletSpeed(bulletSpeed),
      reloadTime(reloadTime),
      ammo(magazineSize, maxReserve),
      fireCooldown(0.0f),
      reloading(false),
      reloadTimer(0.0f) {}

void Weapon::Update(float deltaTime)
{
    if (fireCooldown > 0.0f)
    {
        fireCooldown -= deltaTime;
        if (fireCooldown < 0.0f) fireCooldown = 0.0f;
    }

    if (reloading)
    {
        reloadTimer += deltaTime;              // counts UP in your design
        if (reloadTimer >= reloadTime)
        {
            ammo.Reload();
            reloading = false;
            reloadTimer = 0.0f;
        }
    }
}

bool Weapon::CanFire() const
{
    return !reloading && fireCooldown <= 0.0f && ammo.HasAmmo();
}

bool Weapon::Fire(Vector2 origin, Vector2 target, std::vector<Bullet>& bullets)
{
    if (!CanFire()) return false;
    if (Vector2Length(Vector2Subtract(target, origin)) == 0.0f) return false;

    bullets.emplace_back(origin, target, bulletSpeed, damage);
    ammo.Consume();
    fireCooldown = 1.0f / fireRate;
    return true;
}

void Weapon::StartReload()
{
    if (reloading || !ammo.CanReload()) return;
    reloading = true;
    reloadTimer = 0.0f;
}

bool Weapon::IsReloading() const { return reloading; }

float Weapon::GetReloadProgress() const
{
    if (!reloading || reloadTime <= 0.0f) return 0.0f;
    float p = reloadTimer / reloadTime;
    return (p > 1.0f) ? 1.0f : p;
}

void Weapon::AddAmmo(int amount) { ammo.AddReserve(amount); }

void Weapon::Reset()
{
    ammo.Reset();
    fireCooldown = 0.0f;
    reloading = false;
    reloadTimer = 0.0f;
}

const std::string& Weapon::GetName() const { return name; }
int Weapon::GetDamage() const { return damage; }
const Ammo& Weapon::GetAmmo() const { return ammo; }