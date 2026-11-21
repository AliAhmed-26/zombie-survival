#include "Map.h"

Map::Map(const std::string& path):texture{LoadTexture(path.c_str())}
{
    if (!IsTextureValid(texture))
    {
        TraceLog(LOG_ERROR, "Failed to load map texture!");
    }
}

void Map::draw()
{
    if (IsTextureValid(texture))
    {
        DrawTexture(texture, 0, 0, WHITE);
    }
    
}

Map::~Map()
{
    UnloadTexture(texture);
}
