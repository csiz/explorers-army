#include "general.h"

Point::Point(int X, int Y):x(X),y(Y){}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}
