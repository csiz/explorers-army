#include "map.h"

Map::Map()
{
    //todo:constructor
}

Map::~Map()
{
    //todo:destructor
}

std::vector<Point> Map::find_path(Point start, Point end)
{
    start = start - current_offset;
    end = end - current_offset;

    //todo:do a star path finding
}
