#include "contour.h"
#include "image.h"
#include "liste.h"
#include "masque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <image>", argv[0]);
		exit(1);
	}

	Image I = lire_fichier_image(argv[1]);
	/*Liste L = trouver_contour(I);
	printf("Nombre de segments : %i\n", longueur_liste(L) - 1);*/

	char * ext = ".contours";
	*strrchr(argv[1], '.') = 0;
	char * filename = malloc(strlen(argv[1])+strlen(ext));
	strcpy(filename, argv[1]);
	filename = strcat(argv[1], ext);
	FILE * fd = fopen(filename, "w");

	Liste listes[512];
	int nb_contours = 0;
	Image masque = creer_masque(I);
	int L = largeur_image(I);
	int H = hauteur_image(I);

	for (int i = 0; i < L * H; i++) {
		if (get_pixel_image(masque, i%L+1, i/L+1) == NOIR)
			listes[nb_contours++] = trouver_contour(I, masque);
	}

	fprintf(fd, "%i\n\n", nb_contours);
	for (int i = 0; i < nb_contours; i++) {
		fprintf(fd, "%i\n", longueur_liste(listes[i])-1);
		Cellule * c = listes[i].t;
		while (c) {
			fprintf(fd, " %.1lf %.1lf\n", c->p.x, c->p.y);
			c = c->n;
		}
		fprintf(fd, "\n");
	}

	fclose(fd);

	return 0;
}
