#ifndef SIMPLIFICATION_H
#define SIMPLIFICATION_H

#include "liste.h"

Liste * douglas_peucker(Liste * L, double d);
Liste * douglas_peucker_b2(Liste * L, double d);
Liste * douglas_peucker_b3(Liste * L, double d);

#endif
