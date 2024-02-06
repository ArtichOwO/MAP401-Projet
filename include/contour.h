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

char * orientation_to_string(Orientation o);

void memoriser_position(RobotContour * rc);

Point trouver_pixel_depart(Image I)

#endif
