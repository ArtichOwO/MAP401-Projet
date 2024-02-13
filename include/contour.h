#ifndef CONTOUR_H
#define CONTOUR_H

#include "geom2d.h"
#include "image.h"
#include "liste.h"

typedef enum {
	NORD, SUD, EST, OUEST
} Orientation;

typedef struct {
	Point pos;
	Orientation o;
} RobotContour;

Cellule * trouver_contour(Image I);

#endif
