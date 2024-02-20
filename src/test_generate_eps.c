#include "eps.h"
#include "image.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool fill = false;
    char *mode = malloc(8);

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage : %s <image>\n", argv[0]);
        return 1;
    } else if (argc == 3 ) {
        if (!strcmp(argv[2], "fill")) fill = true;
    }

    if (fill) {
        mode = "_fill";
    }
    else {
        mode = "_stroke";
    }

    Image I = lire_fichier_image(argv[1]);

    // gen filename
    char *ext = ".eps";
    *strrchr(argv[1], '.') = 0;
    char *filename = malloc(strlen(argv[1]) + strlen(ext));
    strcpy(filename, argv[1]);
    filename = strcat(strcat(argv[1], mode), ext);

    FILE *dest = fopen(filename, "w");

    generate_eps(dest, I, fill);
    fclose(dest);
    
    return 0;
}
