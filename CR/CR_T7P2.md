# MAP401 Projet logiciel
## Tâche 7, Partie 2
> Maël Perrier, Léo Grange

### `bezier.h`

Ajout de la fonction `distance_point_bezier3`.

```diff
#ifndef BEZIER_H
#define BEZIER_H

#include "geom2d.h"
#include "liste.h"

typedef struct {
	Point C0;
	Point C1;
	Point C2;
} Bezier2;

typedef struct {
	Point C0;
	Point C1;
	Point C2;
	Point C3;
} Bezier3;

Point CalculBezier2(Bezier2 B, double t);
Point CalculBezier3(Bezier3 B, double t);

Bezier3 Bezier2to3(Bezier2 B);

Bezier2 approx_bezier2(Liste L);
Bezier3 approx_bezier3(Liste L);

double distance_point_bezier2(Bezier2 B, Point Pj, double ti);
+ double distance_point_bezier3(Bezier3 B, Point Pj, double ti);

void print_bezier2(Bezier2 B);
void print_bezier3(Bezier3 B);

#endif
```

### `simplification.h`

Ajout de la fonction `douglas_peucker_b3`.

```diff
#ifndef SIMPLIFICATION_H
#define SIMPLIFICATION_H

#include "liste.h"

Liste * douglas_peucker(Liste * L, double d);
Liste * douglas_peucker_b2(Liste * L, double d);
+ Liste * douglas_peucker_b3(Liste * L, double d);

#endif
```

***

### `test_bezier.c`

```c
#include "bezier.h"
#include "geom2d.h"
#include "liste.h"
#include <stdio.h>

int main(int argc, char * argv[]) {
	Point P0 = set_point(0, 0);
	Point P1 = set_point(1, 0);
	Point P2 = set_point(1, 1);
	Point P3 = set_point(1, 2);
	Point P4 = set_point(2, 2);
	Point P5 = set_point(3, 2);
	Point P6 = set_point(3, 3);
	Point P7 = set_point(4, 3);
	Point P8 = set_point(5, 3);

	printf("+----------+\n"
		   "| Bézier 2 |\n"
		   "+----------+\n");

	Liste L = { NULL };
	ajouter_element_liste(&L, P0);
	ajouter_element_liste(&L, P1);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=1 ###\n");
	Bezier2 B1 = approx_bezier2(L);
	print_bezier2(B1);
	printf("\n");

	ajouter_element_liste(&L, P2);
	ajouter_element_liste(&L, P3);
	ajouter_element_liste(&L, P4);
	ajouter_element_liste(&L, P5);
	ajouter_element_liste(&L, P6);
	ajouter_element_liste(&L, P7);
	ajouter_element_liste(&L, P8);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N≥2 ###\n");
	Bezier2 B2 = approx_bezier2(L);
	print_bezier2(B2);
	printf("\n");

	printf("+----------+\n"
		   "| Bézier 3 |\n"
		   "+----------+\n");

	free_liste(&L);
	ajouter_element_liste(&L, P0);
	ajouter_element_liste(&L, P1);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=1 ###\n");
	Bezier3 B3 = approx_bezier3(L);
	print_bezier3(B3);
	printf("\n");

	ajouter_element_liste(&L, P2);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N=2 ###\n");
	Bezier3 B4 = approx_bezier3(L);
	print_bezier3(B4);
	printf("\n");

	ajouter_element_liste(&L, P3);
	ajouter_element_liste(&L, P4);
	ajouter_element_liste(&L, P5);
	ajouter_element_liste(&L, P6);
	ajouter_element_liste(&L, P7);
	ajouter_element_liste(&L, P8);

	printf("## Liste ##\n");
	imprimer_liste(L);

	printf("### N≥3 ###\n");
	Bezier3 B5 = approx_bezier3(L);
	print_bezier3(B5);
	printf("\n");

	return 0;
}
```

***

### `Asterix3.pbm`

|Contours initiaux|D=1|D=3|D=10|D=30|
|-----------------|---|---|----|----|
|12959 segments|648 courbes|242 courbes|135 courbes|58 courbes|
|![Asterix3_init](img_t7p2/Asterix3_init.jpg)|![Asterix3_d1](img_t7p2/Asterix3_d1.jpg)|![Asterix3_d3](img_t7p2/Asterix3_d3.jpg)|![Asterix3_d10](img_t7p2/Asterix3_d10.jpg)|![Asterix3_d30](img_t7p2/Asterix3_d30.jpg)|

### `lettre-L-cursive.pbm`

|Contours initiaux|D=1|D=3|D=10|D=30|
|-----------------|---|---|----|----|
|4232 segments|157 courbes|32 courbes|22 courbes|13 courbes|
|![lettre-L-cursive_init](img_t7p2/lettre-L-cursive_init.jpg)|![lettre-L-cursive_d1](img_t7p2/lettre-L-cursive_d1.jpg)|![lettre-L-cursive_d3](img_t7p2/lettre-L-cursive_d3.jpg)|![lettre-L-cursive_d10](img_t7p2/lettre-L-cursive_d10.jpg)|![lettre-L-cursive_d30](img_t7p2/lettre-L-cursive_d30.jpg)|

### `ColombesDeLaPaix.pbm`

|Contours initiaux|D=1|D=3|D=10|D=30|
|-----------------|---|---|----|----|
|21871 segments|1155 courbes|451 courbes|230 courbes|138 courbes|
|![ColombesDeLaPaix_init](img_t7p2/ColombesDeLaPaix_init.jpg)|![ColombesDeLaPaix_d1](img_t7p2/ColombesDeLaPaix_d1.jpg)|![ColombesDeLaPaix_d3](img_t7p2/ColombesDeLaPaix_d3.jpg)|![ColombesDeLaPaix_d10](img_t7p2/ColombesDeLaPaix_d10.jpg)|![ColombesDeLaPaix_d30](img_t7p2/ColombesDeLaPaix_d30.jpg)|
