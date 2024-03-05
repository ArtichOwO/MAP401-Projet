#include "types_macros.h"
#include "image.h"
#include <stdio.h>

#include "masque.h"

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	Image im = lire_fichier_image(argv[1]);

	ecrire_image(im);
	printf("\n");
	ecrire_image(masque(im));
	printf("\n");
	ecrire_image(negatif_image(im));
	printf("\n");
	
	return 0;
}
