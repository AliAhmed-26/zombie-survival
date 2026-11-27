#pragma once
#include "raylib.h"
#include<string>
#include<vector>

class Map
{
private:
    Texture2D texture;
    std::vector<Rectangle>obstacles;
    void storeObstacles();
public:
    // CONSTRUCTOR WILL LOAD MAP FROM ASSETS AND STORE THA MAP IN TEXTURE2D
    Map(const std::string& path);

    // AVOID COPYING OF MAP OBJECT USING COPY CONCTRUCTOR AND COPY ASSIGNMENT OPERATOR
    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    // RETURNS ALL THE OBSTACLE IN THE MAP AS A VECTOR
    const std::vector<Rectangle>& getObstacles() const;

    // WILL DRAW MAP USING TEXTURE2D
    void draw();

    // DESTRUCTOR UNLOADS THE MAP WHEN THE GAME OBJECT IS DESTROYED
    ~Map();

};