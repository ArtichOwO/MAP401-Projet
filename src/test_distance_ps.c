#include "geom2d.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "Usage: %s P.x P.y A.x A.y B.x B.y\n", argv[0]);
        exit(1);
    }

    Point P = set_point(atof(argv[1]), atof(argv[2]));
    Point A = set_point(atof(argv[3]), atof(argv[4]));
    Point B = set_point(atof(argv[5]), atof(argv[6]));

    printf("Distance : %lf\n", distance_ps(P, A, B));
}
