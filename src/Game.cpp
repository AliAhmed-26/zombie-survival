#include <iostream>
#include "Game.h"
using namespace std;

Game::Game( // player
    Vector2 position_player, float speed_player, Color color_player, float width_player, float height_player, unsigned int maxHealth_player,
    // weapon
    const std::string &name_weapon, int damage_weapon, float fireRate_weapon, float bulletSpeed_weapon, float reloadTime_weapon, int magazineSize_weapon, int maxReserve_weapon) : player{position_player, speed_player, color_player, width_player, height_player, maxHealth_player}, weapon{name_weapon, damage_weapon, fireRate_weapon, bulletSpeed_weapon, reloadTime_weapon, magazineSize_weapon, maxReserve_weapon}
{
}

Vector2 getRandomPosition()
{
    return {
        (float)(rand() % 1600),
        (float)(rand() % 850)};
}

void Game::play()
{
    for (int i = 0; i < 5; i++)
        weakZombies.emplace_back(getRandomPosition());

    for (int i = 0; i < 3; i++)
        strongZombies.emplace_back(getRandomPosition());

    while (!WindowShouldClose())
    {
        float timeFrame = GetFrameTime();

        // INPUT
        player.handleInput();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            weapon.Fire(
                player.getCenter(),
                GetMousePosition(),
                bullets);
        }

        if (IsKeyPressed(KEY_R))
        {
            weapon.StartReload();
        }
        weapon.Update(timeFrame);

        // UPDATE
        player.move(timeFrame, map.getObstacles());
        player.rotateTowardsMouse();

        for (auto &zombie : weakZombies)
        {
            zombie.followPlayer(player.getPosition(), timeFrame);
            zombie.move(timeFrame, map.getObstacles());
        }

        for (auto &zombie : strongZombies)
        {
            zombie.followPlayer(player.getPosition(), timeFrame);
            zombie.move(timeFrame, map.getObstacles());
        }

        for (auto &bullet : bullets)
        {
            bullet.Update(timeFrame);
        }

        // DRAW
        BeginDrawing();
        ClearBackground(BLACK);

        map.draw();
        player.draw();

        for (auto &zombie : weakZombies)
            zombie.draw();

        for (auto &zombie : strongZombies)
            zombie.draw();

        for (auto &bullet : bullets)
            bullet.Draw();

        EndDrawing();
    }
}