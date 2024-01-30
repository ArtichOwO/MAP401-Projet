#ifndef CONTOUR_H
#define CONTOUR_H

typedef enum {
	NORD, SUD, EST, OUEST
} Orientation;

typedef struct {
	double x;
	double y;
	Orientation o;
} RobotContour;

#endif
