#include "Ammo.h"
#include <algorithm>

Ammo::Ammo(int magazineSize, int maxReserve)
    : magazineSize(magazineSize),
      currentMagazine(magazineSize),   // start with a full magazine
      reserveAmmo(maxReserve),         // start with full reserve
      maxReserve(maxReserve) {}

bool Ammo::HasAmmo() const { return currentMagazine > 0; }

bool Ammo::Consume()
{
    if (!HasAmmo()) return false;
    currentMagazine--;
    return true;
}

bool Ammo::NeedsReload() const { return currentMagazine < magazineSize; }

bool Ammo::CanReload() const { return NeedsReload() && reserveAmmo > 0; }

void Ammo::Reload()
{
    if (!CanReload()) return;
    int needed = magazineSize - currentMagazine;
    int toLoad = std::min(needed, reserveAmmo);
    currentMagazine += toLoad;
    reserveAmmo -= toLoad;
}

void Ammo::AddReserve(int amount)
{
    if (amount <= 0) return;
    reserveAmmo = std::min(reserveAmmo + amount, maxReserve);
}

void Ammo::Reset()
{
    currentMagazine = magazineSize;
    reserveAmmo = maxReserve;
}

int Ammo::GetCurrentMagazine() const { return currentMagazine; }
int Ammo::GetMagazineSize() const { return magazineSize; }
int Ammo::GetReserveAmmo() const { return reserveAmmo; }
int Ammo::GetMaxReserve() const { return maxReserve; }