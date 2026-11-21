#include "Player.h"

Player::Player(Vector2 position_arg, float speed_arg, Color color_arg, float width_arg, float height_arg, unsigned int maxHealth_arg):Person(position_arg,speed_arg,color_arg,maxHealth_arg),width{width_arg},height{height_arg}{}

void Player::setWidth(float w)
{
    width  = w;
}

void Player::setHeight(float h)
{
    height = h;
}

float Player::getWidth() const
{
    return width;
}

float Player::getHeight() const 
{
    return height;
}

Rectangle Player::getBounds() const
{
    return Rectangle{position.x,position.y,width,height};
}

void Player::checkBoundary()
{
    if (position.x < 0)
    {
        position.x = 0;
    }

    if (position.y < 0)
    {
        position.y = 0;
    }

    if ((position.y + height) > GetScreenHeight())
    {
        position.y = GetScreenHeight() - height;
    }
    
    if ((position.x + width) > GetScreenWidth())
    {
        position.x = GetScreenWidth() - width;
    }
}


void Player::handleInput()
{   
    movementDirection.x = 0;
    movementDirection.y = 0;
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        movementDirection.y = -1;
    }
    
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        movementDirection.y = 1;
    }

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        movementDirection.x = 1;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        movementDirection.x = -1;
    }

}

void Player::move(float dt)
{
    position.x += movementDirection.x * speed * dt;
    position.y += movementDirection.y * speed * dt;
    checkBoundary();
}


void Player::draw() const
{   
    DrawRectangleRec(getBounds(),color);
}


int main()
{
    InitWindow(800, 600, "Zombie Survival");
    SetTargetFPS(60);

    Player player({100, 100}, 200, BLUE, 40, 60);

    while (!WindowShouldClose())
    {
        player.handleInput();
        player.move(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        player.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}