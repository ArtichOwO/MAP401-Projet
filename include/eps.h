#ifndef EPS_H
#define EPS_H

#include <stdio.h>
#include "image.h"
#include "bezier.h"

void generate_eps_seg(FILE * fd, Image I, bool fill, double d);
void generate_eps(FILE * fd, Image I, bool fill, double d, BezierType bt);

#endif
