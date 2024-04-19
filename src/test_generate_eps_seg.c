#include "eps.h"
#include "image.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool fill = false;
    char *mode = malloc(8);
    double d = 5;

    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage : %s <image>\n", argv[0]);
        return 1;
    }
    
    if (argc > 2) {
        fill = !strcmp(argv[2], "fill");
    }

    if (argc == 4) {
        d = atoi(argv[3]);
    }

    mode = fill ? "fill" : "stroke";

    Image I = lire_fichier_image(argv[1]);

    *strrchr(argv[1], '.') = 0;
    char filename[512];
    strcpy(filename, argv[1]);
    sprintf(filename, "%s_seg_%s_d%.0lf.eps", argv[1], mode, d);

    FILE *dest = fopen(filename, "w");

    generate_eps_seg(dest, I, fill, d);
    fclose(dest);
    
    return 0;
}
