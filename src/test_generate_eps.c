#include "eps.h"
#include "image.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool fill = false;
    char *mode = malloc(8);
    double d = 5;
    int bezier = 3;

    if (argc < 2 || argc > 5) {
        fprintf(stderr, "Usage : %s <image> [mode [d [bezier:2|3]]]\n", argv[0]);
        return 1;
    }
    
    if (argc > 2) {
        fill = !strcmp(argv[2], "fill");
    }

    if (argc > 3) {
        d = atoi(argv[3]);
    }

    if (argc > 4) {
        bezier = atoi(argv[4]);
    }

    mode = fill ? "fill" : "stroke";

    Image I = lire_fichier_image(argv[1]);

    *strrchr(argv[1], '.') = 0;
    char filename[512];
    strcpy(filename, argv[1]);
    sprintf(filename, "%s_%s_d%.0lf_b%i.eps", argv[1], mode, d, bezier);

    FILE *dest = fopen(filename, "w");

    generate_eps(dest, I, fill, d, bezier);
    fclose(dest);
    
    return 0;
}
