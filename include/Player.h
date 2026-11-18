#include "../include/Person.h"
#include "raylib.h"


class Player : public Person
{
private:
    float width;
    float height;
    Vector2 movementDirection{0,0};

public:
    Player(Vector2 position_arg, float speed_arg, Color color_arg, float width_arg, float height_arg, unsigned int maxHealth_arg = 100);

    //SETTING WIDTH AND HEIGHT FOR PLAYER RECTANGLE
    void setWidth(float w);
    void setHeight(float h);

    float getWidth() const;
    float getHeight() const;

    //HANDLE INPUT FOR PLAYER MOVEMENT e.g W,D,A,S
    void handleInput();

    //KEEPS THE PLAYER WITHIN THE GAME WINDOW
    void checkBoundary();

    //RETURN THE PLAYER RECTANGLES WILL BE USED FOR COLLISION BETWEEN PLAYER AND ZOMBIE
    Rectangle getBounds() const; 

    void move(float dt) override;
    void draw() const override;

};