#ifndef BEZIER_H
#define BEZIER_H

#include "geom2d.h"
#include "liste.h"

typedef struct {
	Point C0;
	Point C1;
	Point C2;
} Bezier2;

typedef struct {
	Point C0;
	Point C1;
	Point C2;
	Point C3;
} Bezier3;

Point CalculBezier2(Bezier2 B, double t);
Point CalculBezier3(Bezier3 B, double t);

Bezier3 Bezier2to3(Bezier2 B);

Bezier2 approx_bezier2(Liste L);

#endif
