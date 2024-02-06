#include "contour.h"
#include "geom2d.h"
#include "image.h"
#include <stdio.h>

char * orientation_to_string(Orientation o) {
	switch (o) {
		case NORD:
			return "NORD";
		case SUD:
			return "SUD";
		case EST:
			return "EST";
		case OUEST:
			return "OUEST";
	}
}

void memoriser_position(RobotContour * rc) {
	printf("(%.0lf, %.0lf, %s)\n", rc->x, rc->y, orientation_to_string(rc->o));
}

void tourner_gauche(RobotContour * rc) {
	switch (rc->o) {
		case NORD:
			rc->o = OUEST;
			break;
		case SUD:
			rc->o = EST;
			break;
		case EST:
			rc->o = NORD;
			break;
		case OUEST:
			rc->o = SUD;
	}
}

void tourner_droite(RobotContour * rc) {
	switch (rc->o) {
		case NORD:
			rc->o = EST;
			break;
		case SUD:
			rc->o = OUEST;
			break;
		case EST:
			rc->o = SUD;
			break;
		case OUEST:
			rc->o = NORD;
	}
}

void avancer(RobotContour * rc) {
	switch (rc->o) {
		case NORD:
			rc->y--;
			break;
		case SUD:
			rc->y++;
			break;
		case EST:
			rc->x++;
			break;
		case OUEST:
			rc->x--;
	}
}

void nouvelle_orientation(Image I, RobotContour * rc) {
	Pixel D, G;
	switch (rc->o) {
		case NORD:
			G = get_pixel_image(I, rc->x, rc->y);
			D = get_pixel_image(I, rc->x+1, rc->y);
			break;
		case SUD:
			G = get_pixel_image(I, rc->x+1, rc->y+1);
			D = get_pixel_image(I, rc->x, rc->y+1);
			break;
		case EST:
			G = get_pixel_image(I, rc->x+1, rc->y);
			D = get_pixel_image(I, rc->x+1, rc->y+1);
			break;
		case OUEST:
			G = get_pixel_image(I, rc->x, rc->y+1);
			D = get_pixel_image(I, rc->x, rc->y);
	}

	if (G == NOIR)
		tourner_gauche(rc);
	else if (D == BLANC)
		tourner_droite(rc);
}

Point trouver_pixel_depart(Image I) {
	int L = largeur_image(I);
	int H = hauteur_image(I);
	Point P = {0, 0};

	for (int i = 0; i < L * H; i++)
	{
		if (get_pixel_image(I, i%L + 1, i/H + 1) == BLANC && get_pixel_image(I, i%L + 1, i/H + 1) == NOIR) {
			P.x = i % L + 1;
			P.y = (double)i / H + 1;
			return P;
		}
	}

	return P;
}

void trouver_contour(Image I) {
	Point depart = trouver_pixel_depart(I);
	depart.x--;
	depart.y--;

	RobotContour rc = {
		.x = depart.x,
		.y = depart.y,
		.o = EST
	};

	do {
		memoriser_position(&rc);
		avancer(&rc);
		nouvelle_orientation(I, &rc);

		if (rc.x == depart.x && rc.y == depart.y && rc.o == EST)
			break;
	} while (true);
}
