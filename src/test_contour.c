#include "contour.h"
#include "image.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <image>", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);
	Cellule * L = trouver_contour(I);
	imprimer_liste(L);
	printf("Nombre de segments : %i\n", longueur_liste(L) - 1);

	char * ext = ".contours";
	*strrchr(argv[1], '.') = 0;
	argv[1] = realloc(argv[1], strlen(argv[1])+strlen(ext));
	char * filename = strcat(argv[1], ext);
	FILE * fd = fopen(filename, "w");

	fprintf(fd, "1\n\n%i\n", longueur_liste(L));
	while (L) {
		fprintf(fd, " %.1lf %.1lf", L->p.x, L->p.y);
		L = L->n;
	}

	return 0;
}
