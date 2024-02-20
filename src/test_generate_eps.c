#include "eps.h"
#include "image.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s <image>\n", argv[0]);
        return 1;
    }

    Image I = lire_fichier_image(argv[1]);

    // gen filename
    char *ext = ".eps";
    *strrchr(argv[1], '.') = 0;
    char *filename = malloc(strlen(argv[1]) + strlen(ext));
    strcpy(filename, argv[1]);
    filename = strcat(argv[1], ext);

    FILE *dest = fopen(filename, "w");

    generate_eps(dest, I);
    fclose(dest);
    
    return 0;
}
