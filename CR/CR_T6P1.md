# MAP401 Projet logiciel
## Tâche 6, Partie 1
> Maël Perrier, Léo Grange

### `distance_ps`

```c
double distance_ps(Point P, Point A, Point B) {
    Vecteur AP = vect_bipoint(A, P);
    Vecteur AB = vect_bipoint(A, B);
    double lambda = produit_scalaire(AP, AB) 
                  / produit_scalaire(AB, AB);

    if (lambda < 0)
        return point_norme(A, P);
    else if (lambda > 1)
        return point_norme(B, P);
    else {
        Point Q = add_point(A, 
            produit_reel_point(
                sub_point(B, A), lambda));
        return point_norme(Q, P);
    }
}
```

### `test_distance_ps.c`

```c
#include "geom2d.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "Usage: %s P.x P.y A.x A.y B.x B.y\n", argv[0]);
        exit(1);
    }

    Point P = set_point(atof(argv[1]), atof(argv[2]));
    Point A = set_point(atof(argv[3]), atof(argv[4]));
    Point B = set_point(atof(argv[5]), atof(argv[6]));

    printf("Distance : %lf\n", distance_ps(P, A, B));
}
```

### Jeu de tests

A = (2, 3)  
B = (5, 5)  

P1 = (0, 3)  
P2 = (2, 6)  
P3 = (6, 7)  

#### Avec Q ∉ S, Q du côté de A, λ < 0

```
$ ./test_distance_ps 0 3 2 3 5 5
Distance : 2.000000
```

#### Avec Q ∈ S, 0 ≤ λ ≤ 1

```
$ ./test_distance_ps 2 6 2 3 5 5
Distance : 2.496151
```

#### Avec Q ∉ S, Q du côté de B, λ > 1

```
$ ./test_distance_ps 6 7 2 3 5 5
Distance : 2.236068
```
