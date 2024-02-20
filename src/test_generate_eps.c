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

    generate_eps(stdout, I);
    
    return 0;
}