#include "../include/Map.h"
Map::Map() : texture{LoadTexture("assets/environment/map.png")}
{
    scaleX = (float)GetScreenWidth() / texture.width;
    scaleY = (float)GetScreenHeight() / texture.height;
    // STORE THE OBSTCALES
    storeObstacles();

    // SHOWS THE ERROR IF MAP IS NOT LOADED
    if (!IsTextureValid(texture))
    {
        TraceLog(LOG_ERROR, "Failed to load map texture!");
    }
}

// STORING ALL THE OBSTACLES
void Map::storeObstacles()
{
    obstacles = {

        // BUILDING
        {192, 8, 379, 265},
        {1110, 8, 414, 292},
        {1005, 248, 110, 45},

        // FENCES AND WALLS
        {0, 292, 179, 40},
        {292, 847, 120, 45},
        {423, 847, 110, 45},
        {535, 842, 25, 50},
        {1009, 771, 136, 50},

        // FOR RED CAR
        {120, 460, 18, 40},
        {140, 428, 65, 25},
        {195, 436, 65, 20},
        {290, 465, 23, 55},
        {205, 510, 85, 18},
        {130, 495, 80, 20},

        // FOR BLUE CAR
        {1445, 490, 40, 25},
        {1480, 498, 65, 22},
        {1555, 517, 43, 48},
        {1515, 565, 65, 23},
        {1433, 540, 80, 25},
        {1430, 507, 25, 45},

        // AMBULANCE
        {1515, 240, 58, 30},
        {1540, 265, 35, 60},
        {1482, 303, 65, 28},
        {1418, 303, 70, 42},

        // CRATES AND BARRELS
        {224, 262, 39, 57},
        {480, 263, 39, 55},
        {567, 237, 35, 50},
        {518, 262, 35, 51},
        {567, 812, 77, 80},
        {1613, 771, 40, 80},

        // FOR LARGE TREE BELOW RED CAR
        {73, 665, 150, 130},
        {136, 784, 30, 50},
        {175, 765, 15, 30},

        // UPPER STREET LAMP
        {950, 123, 50, 38},
        {978, 145, 10, 90},
        {970, 233, 25, 40},
        // LOWER STREET LAMP
        {1035, 523, 47, 60},
        {1049, 600, 25, 50}};

    for (Rectangle &obstacle : obstacles)
    {
        obstacle.x *= scaleX;
        obstacle.y *= scaleY;
        obstacle.width *= scaleX;
        obstacle.height *= scaleY;
    }
}

// RETURNS ALL THE OBSTACLES IN THE MAP
const std::vector<Rectangle> &Map::getObstacles() const
{
    return obstacles;
}

void Map::draw()
{
    if (IsTextureValid(texture))
    {
        DrawTexturePro(
            texture,
            {0, 0, (float)texture.width, (float)texture.height},
            {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            {0, 0},
            0.0f,
            WHITE);
    }
}

Map::~Map()
{
    UnloadTexture(texture);
}
