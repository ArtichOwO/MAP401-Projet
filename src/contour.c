#include "contour.h"
#include "geom2d.h"
#include "image.h"
#include "liste.h"
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

void memoriser_position(RobotContour rc, Liste * ListePos) {
	ajouter_element_liste(ListePos, rc.pos);
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
			rc->pos.y--;
			break;
		case SUD:
			rc->pos.y++;
			break;
		case EST:
			rc->pos.x++;
			break;
		case OUEST:
			rc->pos.x--;
	}
}

void nouvelle_orientation(Image I, RobotContour * rc) {
	Pixel D, G;
	switch (rc->o) {
		case NORD:
			G = get_pixel_image(I, rc->pos.x, rc->pos.y);
			D = get_pixel_image(I, rc->pos.x+1, rc->pos.y);
			break;
		case SUD:
			G = get_pixel_image(I, rc->pos.x+1, rc->pos.y+1);
			D = get_pixel_image(I, rc->pos.x, rc->pos.y+1);
			break;
		case EST:
			G = get_pixel_image(I, rc->pos.x+1, rc->pos.y);
			D = get_pixel_image(I, rc->pos.x+1, rc->pos.y+1);
			break;
		case OUEST:
			G = get_pixel_image(I, rc->pos.x, rc->pos.y+1);
			D = get_pixel_image(I, rc->pos.x, rc->pos.y);
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
		if (get_pixel_image(I, i%L + 1, i/L) == BLANC
			&& get_pixel_image(I, i%L + 1, i/L + 1) == NOIR) {
			P.x = i % L;
			P.y = i / L;
			return P;
		}
	}

	return P;
}

Liste trouver_contour(Image I) {
	Liste L = { NULL };
	Point depart = trouver_pixel_depart(I);

	RobotContour rc = {
		.pos = depart,
		.o = EST
	};

	do {
		memoriser_position(rc, &L);
		avancer(&rc);
		nouvelle_orientation(I, &rc);

		if (rc.pos.x == depart.x 
			&& rc.pos.y == depart.y 
			&& rc.o == EST)
			break;
	} while (true);

	return L;
}
