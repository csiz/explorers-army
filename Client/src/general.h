#ifndef GENERAL_H
#define GENERAL_H


class Point
{
    public:
        int x;
        int y;
        Point(int x=0, int y=0);
    protected:
    private:
};

Point operator-(Point a,Point b);

#endif // GENERAL_H
