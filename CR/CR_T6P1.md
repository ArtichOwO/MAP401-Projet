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
                sub_point(A, B), lambda));
        return point_norme(Q, P);
    }
}
```

### `test_distance_ps.c`

```c
//
```

### Jeu de tests

#### Avec Q ∉ S, Q du côté de A, λ < 0

```
$
```

#### Avec Q ∈ S, 0 ≤ λ ≤ 1

```
$
```

#### Avec Q ∉ S, Q du côté de B, λ > 1

```
$
```
