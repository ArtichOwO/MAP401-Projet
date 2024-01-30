#ifndef CONTOUR_H
#define CONTOUR_H

#include "types_macros.h"

typedef enum {
	NORD, SUD, EST, OUEST
} Orientation;

typedef struct {
	UINT x;
	UINT y;
	Orientation o;
} RobotContour;

char * orientation_to_string(Orientation o);

void memoriser_position(RobotContour * rc);

#endif
