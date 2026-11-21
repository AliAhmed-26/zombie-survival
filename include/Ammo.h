#ifndef AMMO_H
#define AMMO_H

//  Keeps track of bullets: how many are in the magazine and
//  how many are left in reserve. It does NOT shoot or draw
//  anything - the Weapon class uses it.

class Ammo
{
private:
    int magazineSize;    // max bullets the magazine can hold (12)
    int currentMagazine; // bullets currently loaded
    int reserveAmmo;     // spare bullets carried by the player (60)
    int maxReserve;      // max spare bullets the player can carry

public:
    // Constructor 
    Ammo(int magazineSize = 12, int maxReserve = 60);

    // Using ammo 
    bool HasAmmo() const;        // true if magazine has at least 1 bullet
    bool Consume();              // uses 1 bullet; returns false if empty

    // Reloading 
    bool NeedsReload() const;    // magazine is not full
    bool CanReload() const;      // magazine not full AND reserve > 0
    void Reload();               // moves bullets from reserve into magazine

    // Pickups/reset
    void AddReserve(int amount); // add spare bullets (capped at maxReserve)
    void Reset();                // refill everything (used on game restart)

    // Getters
    int GetCurrentMagazine() const;
    int GetMagazineSize() const;
    int GetReserveAmmo() const;
    int GetMaxReserve() const;
};

#endif // AMMO_H