#include "contour.h"
#include <stdio.h>

char * orientation_to_string(Orientation o) {
	switch (o) {
		case NORD:
			return "NORD";
		case SUD:
			return "SUD";
		case EST:
			return "EST";
		case OUEST:
			return "OUEST";
	}
}

void memoriser_position(RobotContour * rc) {
	printf("(%i, %i, %s)", rc->x, rc->y, orientation_to_string(rc->o));
}
