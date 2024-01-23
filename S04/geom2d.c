#include "geom2d.h"
#include <math.h>
#include "types_macros.h"

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

Vecteur vect_bipoint(Point A, Point B) {
	Vecteur v = {
		.x = B.x - A.x,
		.y = B.y - A.y
	};

	return v;
}

double prod_scalaire(Vecteur A, Vecteur B) {
	return A.x*B.x + A.y*B.y;
}
