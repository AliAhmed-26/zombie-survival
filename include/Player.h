#pragma once
#include "../include/Person.h"
#include "raylib.h"
#include <cmath>

class Player : public Person
{
private:
    float width;
    float height;
    float hitBoxWidth;
    float hitBoxHeight;
    Vector2 movementDirection{0, 0};
    Texture2D playerTexture;
    float rotation = 100;
    float rotationSpeed = 10.0f;
    float targetRotation = 0.0f;

public:
    Player(Vector2 position_arg, float speed_arg, Color color_arg, float width_arg, float height_arg, unsigned int maxHealth_arg);

    // DESTRUCTOR
    ~Player();

    // SETTING WIDTH AND HEIGHT FOR PLAYER RECTANGLE
    void setWidth(float w);
    void setHeight(float h);

    float getWidth() const;
    float getHeight() const;

    // HANDLE INPUT FOR PLAYER MOVEMENT e.g W,D,A,S
    void handleInput();

    // KEEPS THE PLAYER WITHIN THE GAME WINDOW
    void checkBoundary();

    // RETURN THE PLAYER RECTANGLES WILL BE USED FOR COLLISION BETWEEN PLAYER AND ZOMBIE
    Rectangle getPlayer() const;
    Vector2 getCenter() const;

    // CONTROLS THE ROTATION OF PLAYER
    void rotateTowardsMouse();

    // ALLOW THE MOVEMENT OF PLAYER
    void move(float dt, const std::vector<Rectangle> &obstacles) override;

    // DRAW THE PLAYER
    void draw() const override;
};