#ifndef EPS_H
#define EPS_H

#include <stdio.h>
#include "image.h"

void generate_eps_init(FILE * fd, Image I, bool fill);
void generate_eps(FILE * fd, Image I, bool fill, double d);

#endif
