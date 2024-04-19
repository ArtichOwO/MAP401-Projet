# MAP401 Projet logiciel
## Tâche 8
> Maël Perrier, Léo Grange

### Partie 1

#### A. Série `zebres`

|Fichier|Contours|Simplification|Temps (`user`)|
|-------|--------|--------------|-----|
|`zebres-1000x0750.pbm`|&check;|&check;|0.21s|
|`zebres-2000x1500.pbm`|&check;|&check;|0.68s|
|`zebres-3000x2250.pbm`|&check;|&check;|1.48s|
|`zebres-4000x3000.pbm`|&check;|&check;|2.80s|

### B. Série `courbe de Hilbert`

|Fichier|Contours|Simplification|Temps (`user`)|
|-------|--------|--------------|-----|
|`courbe_hilbert_7.pbm`|&check;|&check;|0.06s|
|`courbe_hilbert_8.pbm`|&check;|&check;|0.25s|
|`courbe_hilbert_9.pbm`|&check;|&check;|1.06s|
|`courbe_hilbert_10.pbm`|&check;|&check;|4.52s|

***

### Partie 2

#### Sans simplification

|Fichier|Contours|Segments|
|-------|--------|--------|
|`Asterix3.pbm`|32|7731|
|`lettre-L-cursive.pbm`|3|2384|
|`ColombesDeLaPaix.pbm`|106|13445|

#### Simplification par segments

|Fichier|d = 0|d = 0.5|d = 1|d = 2|d = 4|d = 8|d = 16|
|-------|-----|-------|-----|-----|-----|-----|------|
|`Asterix3.pbm`|7731|6205|1347|668|427|297|186|
|`lettre-L-cursive.pbm`|2384|1908|275|107|78|55|40|
|`ColombesDeLaPaix.pbm`|13445|10581|2559|1240|876|604|430|


#### Simplification par courbes de Bézier de degré 2

|Fichier|d = 0|d = 0.5|d = 1|d = 2|d = 4|d = 8|d = 16|
|-------|-----|-------|-----|-----|-----|-----|------|
|`Asterix3.pbm`|8126|4964|971|374|254|185|119|
|`lettre-L-cursive.pbm`|2736|1706|254|46|33|29|21|
|`ColombesDeLaPaix.pbm`|13672|8398|1624|723|513|333|229|

#### Simplification par courbes de Bézier de degré 3

|Fichier|d = 0|d = 0.5|d = 1|d = 2|d = 4|d = 8|d = 16|
|-------|-----|-------|-----|-----|-----|-----|------|
|`Asterix3.pbm`|11091|3484|644|300|210|155|85|
|`lettre-L-cursive.pbm`|3531|1218|155|40|28|25|16|
|`ColombesDeLaPaix.pbm`|19136|5990|1174|569|389|260|181|

#### Résultats EPS pour `Asterix3.pbm`

|`Asterix3.pbm`|d = 1|d = 2|d = 4|d = 8|
|--------------|-----|-----|-----|-----|
|Segments|![seg_d1](img_t8/seg_d1.jpg)|![seg_d2](img_t8/seg_d2.jpg)|![seg_d4](img_t8/seg_d4.jpg)|![seg_d8](img_t8/seg_d8.jpg)|
|Bézier (2)|![b2_d1](img_t8/b2_d1.jpg)|![b2_d2](img_t8/b2_d2.jpg)|![b2_d4](img_t8/b2_d4.jpg)|![b2_d8](img_t8/b2_d8.jpg)|
|Bézier (3)|![b3_d1](img_t8/b3_d1.jpg)|![b3_d2](img_t8/b3_d2.jpg)|![b3_d4](img_t8/b3_d4.jpg)|![b3_d8](img_t8/b3_d8.jpg)|
