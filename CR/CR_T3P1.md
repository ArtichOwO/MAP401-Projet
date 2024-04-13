# MAP401 Projet logiciel
## Tâche 3, Partie 1
> Maël Perrier, Léo Grange

***

![testimage](img_t3p1/testimage.png)
```pbm
P1
4 4
0100
1111
0010
0110
```
```
$ ./test_contour testimage.pbm
(1, 0, EST)
(2, 0, SUD)
(2, 1, EST)
(3, 1, EST)
(4, 1, SUD)
(4, 2, OUEST)
(3, 2, SUD)
(3, 3, SUD)
(3, 4, OUEST)
(2, 4, OUEST)
(1, 4, NORD)
(1, 3, EST)
(2, 3, NORD)
(2, 2, OUEST)
(1, 2, OUEST)
(0, 2, NORD)
(0, 1, EST)
(1, 1, NORD)
```

***

![personnage](img_t3p1/personnage.png)
```pbm
P1
10 10
0000000000
0001111000
0010000100
0101001010
0100000010
0101001010
0100110010
0010000100
0001111000
0000000000
```
```
$ ./test_contour personnage.pbm
(3, 1, EST)
(4, 1, EST)
(5, 1, EST)
(6, 1, EST)
(7, 1, SUD)
(7, 2, EST)
(8, 2, SUD)
(8, 3, EST)
(9, 3, SUD)
(9, 4, SUD)
(9, 5, SUD)
(9, 6, SUD)
(9, 7, OUEST)
(8, 7, SUD)
(8, 8, OUEST)
(7, 8, SUD)
(7, 9, OUEST)
(6, 9, OUEST)
(5, 9, OUEST)
(4, 9, OUEST)
(3, 9, NORD)
(3, 8, OUEST)
(2, 8, NORD)
(2, 7, OUEST)
(1, 7, NORD)
(1, 6, NORD)
(1, 5, NORD)
(1, 4, NORD)
(1, 3, EST)
(2, 3, NORD)
(2, 2, EST)
(3, 2, NORD)
```

***

![testimage2](img_t3p1/testimage2.png)
```pbm
P1
6 3
110111
011100
110000
```
```
(0, 0, EST)
(1, 0, EST)
(2, 0, SUD)
(2, 1, EST)
(3, 1, NORD)
(3, 0, EST)
(4, 0, EST)
(5, 0, EST)
(6, 0, SUD)
(6, 1, OUEST)
(5, 1, OUEST)
(4, 1, SUD)
(4, 2, OUEST)
(3, 2, OUEST)
(2, 2, SUD)
(2, 3, OUEST)
(1, 3, OUEST)
(0, 3, NORD)
(0, 2, EST)
(1, 2, NORD)
(1, 1, OUEST)
(0, 1, NORD)
```