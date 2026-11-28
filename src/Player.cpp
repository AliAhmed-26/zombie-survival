#include "../include/Player.h"
#include "../include/Map.h"

Player::Player(Vector2 position_arg, float speed_arg, Color color_arg, float width_arg, float height_arg, float hitBoxWidth_arg, float hitBoxHeight_arg, unsigned int maxHealth_arg) : Person(position_arg, speed_arg, color_arg, maxHealth_arg), width{width_arg}, height{height_arg}, hitBoxWidth{hitBoxWidth_arg}, hitBoxHeight{hitBoxHeight_arg}
{
    // LOAD THE PLAYER AND STORE IN THE PLAYERTEXTURE
    playerTexture = LoadTexture("assets/player/player.png");
}

// ----------SETTERS-----------
void Player::setWidth(float w)
{
    width = w;
}

void Player::setHeight(float h)
{
    height = h;
}

//  -------GETTERS--------
float Player::getWidth() const
{
    return width;
}

float Player::getHeight() const
{
    return height;
}

//  RETURN THE PLAYER RECTANGLE E.G POSITION,WIDTH AND HEIGHT
Rectangle Player::getPlayer() const
{
    return Rectangle{position.x + (width - hitBoxWidth) / 2, position.y + (height - hitBoxHeight) / 2, hitBoxWidth, hitBoxHeight};
}

// KEEPS THE PLAYER WITH IN TH WINDOW
void Player::checkBoundary()
{
    // CHECKS FOR LEFT BOUNDARY
    if (position.x < 0)
    {
        position.x = 0;
    }

    // CHECKS FOR UPPER BOUNDARY
    if (position.y < 0)
    {
        position.y = 0;
    }

    // CHECKS FOR BOTTOM BOUNDARY
    if ((position.y + height) > GetScreenHeight())
    {
        position.y = GetScreenHeight() - height;
    }

    // CHECKS FOR RIGHT BOUNDARY
    if ((position.x + width) > GetScreenWidth())
    {
        position.x = GetScreenWidth() - width;
    }
}

// HANDLE INPUT FROM KEYBOARD FOR MOVEMENT OF PLAYER
void Player::handleInput()
{
    movementDirection.x = 0;
    movementDirection.y = 0;

    // FOR MOVING PLAYER UPWARD
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        movementDirection.y = -1;
    }

    // FOR MOVING PLAYER DOWNWARD
    else if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        movementDirection.y = 1;
    }

    // FOR MOVING PLAYER RIGHT
    else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        movementDirection.x = 1;
    }

    // FOR MOVING PLAYER LEFT
    else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        movementDirection.x = -1;
    }
}

// FOR MOVEMENT OF PLAYER
void Player::move(float dt, const std::vector<Rectangle> &obstacles)
{
    Vector2 nextPosition = position;
    // FOR RIGHT AND LEFT MOVEMENT
    nextPosition.x += movementDirection.x * speed * dt;

    // FRO UPWARD AND DOWNWARD MOVEMENT
    nextPosition.y += movementDirection.y * speed * dt;

    // RECTANGLE OF PLAYER AT THE PROPOSED LOCATION
    Rectangle nextPositionPlayer = {nextPosition.x + (width - hitBoxWidth) / 2, nextPosition.y + (height - hitBoxHeight) / 2, hitBoxWidth, hitBoxHeight};

    // CHECKS WHETHER THE NEXT POSITION OF PLAYER OVERLAPS WITH THE OBSTACLE
    if (canMoveTo(nextPositionPlayer, obstacles))
    {
        position = nextPosition;
    }

    // KEEPS THE PLAYER INSIDE THE WINDOW
    checkBoundary();
}

// ROTATES THE PLAYER ACCORDING TO THE DIRECTION IN WHICH THE MOUSE MOVES
void Player::rotateTowardsMouse()
{
    Vector2 mouseMovement = GetMouseDelta();
    if (mouseMovement.x != 0 || mouseMovement.y != 0)
    {
        float angle = std::atan2(mouseMovement.y, mouseMovement.x) * RAD2DEG;
        targetRotation = angle - 90.0f;
    }
    float difference = std::remainder(targetRotation - rotation, 360.0f);
    rotation += difference * rotationSpeed * GetFrameTime();
}

// DRAW THE PLAYER ON SCREEN
void Player::draw() const
{
    DrawTexturePro(playerTexture, Rectangle{0, 0, (float)playerTexture.width, (float)playerTexture.height},
                   Rectangle{position.x + width / 2, position.y + height / 2, width, height}, Vector2{width / 2, height / 2}, rotation, WHITE);
    DrawRectangleLinesEx(getPlayer(), 1, RED);
}

// DESCTRUCT THE PLAYER
Player::~Player()
{
    // UNLOAD THE PLAYER FROM GPU
    UnloadTexture(playerTexture);
}
