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

        std::vector<std::vector<MapTile> > map;

        std::vector<Point> find_path(Point start, Point end);

    protected:
    private:


};

#endif // MAP_H
