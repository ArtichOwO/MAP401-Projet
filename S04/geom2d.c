#include "geom2d.h"
#include <math.h>

Point set_point(double x, double y)
{
    Point P;
    P.x = x;
    P.y = y;
    return P;
}

Point add_point(Point P1, Point P2)
{
    Point P;
    P.x = P1.x + P2.x;
    P.y = P1.y + P2.y;
    return P;
}