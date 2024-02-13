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
	Liste L = trouver_contour(I);
	imprimer_liste(L);
	printf("Nombre de segments : %i\n", longueur_liste(L) - 1);

	char * ext = ".contours";
	*strrchr(argv[1], '.') = 0;
	char * filename = malloc(strlen(argv[1])+strlen(ext));
	strcpy(filename, argv[1]);
	filename = strcat(argv[1], ext);
	FILE * fd = fopen(filename, "w");

	fprintf(fd, "1\n\n%i\n", longueur_liste(L));
	Cellule * c = L.t;
	while (c) {
		fprintf(fd, " %.1lf %.1lf", c->p.x, c->p.y);
		c = c->n;
	}

	fclose(fd);

	return 0;
}
