#include "geom2d.h"
#include <math.h>

Point set_point(double x, double y)
{
    Point P = {x ,y};
    return P;
}

Point add_point(Point P1, Point P2)
{
    Point P = { P1.x + P2.x, P1.y + P2.y};
    return P;
}

Vecteur vect_bipoint(Point A, Point B) {
	Vecteur v = {
		.x = B.x - A.x,
		.y = B.y - A.y
	};

	return v;
}
