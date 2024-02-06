#include "contour.h"
#include "image.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <image>", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);
	trouver_contour(I);

	return 0;
}
