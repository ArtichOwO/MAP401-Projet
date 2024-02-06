#ifndef CONTOUR_H
#define CONTOUR_H

#include "image.h"

typedef enum {
	NORD, SUD, EST, OUEST
} Orientation;

typedef struct {
	double x;
	double y;
	Orientation o;
} RobotContour;

void trouver_contour(Image I);

Point trouver_pixel_depart(Image I)

#endif
