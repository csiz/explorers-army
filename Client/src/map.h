#ifndef MAP_H
#define MAP_H

#include <vector>

#include "maptile.h"
#include "general.h"

class Map
{
    public:
        Map();
        ~Map();

        MapTile& operator()(int x, int y);
        std::vector<Point> find_path(Point start, Point end);
    protected:
    private:
        std::vector<std::vector<MapTile> > current_tiles;
        Point current_offset;

};

#endif // MAP_H
