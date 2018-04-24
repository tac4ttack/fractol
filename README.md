# Fract'ol

*Ce projet consiste à créer graphiquement de jolies fractales...*

## Installation

### Téléchargement

* Pour cloner ce projet vous pouvez faire la commande suivante:

	>`$ git clone https://gitlab.com/tacattack/fractol.git`

* Après clonage du `fractol.git` le répertoire `libft` est présent mais vide.
Vous devez exécuter deux commandes:
	
	- Pour initialiser votre fichier local de configuration:

		>`$ git submodule init`

	- Pour tirer toutes les données de ce projet et récupérer le `commit` approprié tel que listé dans votre projet:

		>`$ git submodule update`

* Il existe une autre manière plus simple d’arriver au même résultat.
Si vous passez l’option `--recursive` à la commande git clone, celle-ci
initialisera et mettra à jour automatiquement chaque sous-module du dépôt.

	>`$ git clone --recursive https://gitlab.com/tacattack/fractol.git`

* Penser à configurer le `status.submodulesummary` pour pouvoir voir les commits
des submodules:

	>`$ git config --global status.submodulesummary true`

## Utilisation

### Prérequis
1. Système d'exploitation
 	* Distribution Linux avec `Server X11`.
	* MacOSX 10.11 `El Capitan`.
	* MacOSX 10.12 `Sierra`.

2. Matériel
	* Clavier.
	* Souris.
	* Une paire d'yeux.
	* Optionnel: carte graphique compatible `OpenCL`

3. Bibliothèques
	- Bibliothèque graphique `MLX`, présente dans le dépot et compilée automatiquement selon votre système d'exploitation.
	- Bibliothèque standard du C ISO `libc` pour pouvoir inclure les fichiers suivants:
		`<stdlib.h> <limits.h>	<fcntl.h> <math.h> <complex.h>`
	- Bibliothèque standard du cursus 42 `libft`, présente sur le dépot et compilée automatiquement.
	- Bibliothèque `OpenCL` pour la parallélisation des calculs sur le `GPU`.
	*Attention l'accélération graphique n'est pas encore implémentée! Il est possible de lancer la compilation avec cette fonctionnalité et les bibliothèques nécessaires seront alors requises!*

### Compilation

Pour compiler ce projet un `$ makefile` est à disposition, celui-ci propose les options suivantes:

* Compilation pour fonctionnement sur un seul thread du CPU:

	>`$ make cpu`

* Compilation de la `libft` uniquement:

	>`$ make libft`

* Compilation de la `MLX` uniquement (version nécessaire déterminée automatiquement):

	>`$ make mlx`

* Vérification de la `norme 42` pour le code en C sur les fichiers sources et headers:

	>`$ make norme`

* Suppression des fichiers sources compilés non liés (`.obj`) dans le répertoire temporaire de `fractol`:

	>`$ make clean`

* Suppression des fichiers sources compilés et non liés (`.obj`) dans le répertoire de la `libft`:

	>`$ make cleanlibft`

* Suppression des fichiers sources compilés et non liés (`.obj`) dans les répertoire de la `MLX`:

	>`$ make cleanmlx`

* Suppression du binaire et des fichiers sources compilés non liés (`.obj`) du répertoire de `fractol` ainsi que des bibliothèques `libft` et `MLX`:

	>`$ make fclean`

* Suppression de la bibliothèque `libft.a` et des fichiers sources compilés non liés (`.obj`) dans le répertoire de la `libft`:

	>`$ make fcleanlibft`

* Remise à zéro et recompilation de `fractol` en utilisant qu'un seul thread du CPU:

	>`$ make re`

* Compilation pour fonctionnement avec accélération graphique:

	>`$ make gpu`

	*** *Attention l'accélération graphique n'est pas encore implémentée! Il est possible de lancer la compilation avec cette fonctionnalité mais le comportement du programme sera identique à la compilation normale avec `make cpu` !* ***

* Si vous voulez activer la sortie de `debug`, ajoutez l'option `debug` avant l'option `cpu` ou `gpu`, exemple:
	>`$ make debug cpu`

	*** *Attention à bien effectuer un `make fclean` avant d'utiliser l'option `debug` !* ***

### Lancement
L'exécution du binaire `fractol` vous affichera son usage tel que:
>```
>$ ./fractol
>
> Usage: ./fractol [type]
>------
>
>Available fractal types:
>------------------------
>mandelbrot -> the Mandelbrot set
>tricorn -> the Tricorn set aka Mandelbar
>julia -> the Julia set
>burning -> the Burning Ship set
>celtic -> the Celtic set
>mandeldrop -> the Mandeldrop set
>
>You can launch multiple fractals separating them with a space
>```

Les fractales rendues par ce `fractol` sont les suivantes:
* L'ensemble de `Mandelbrot` et ses dérivées en fonction de l'exposant formant l'ensemble `Multibrot`
* La `Julia` et ses dérivées en fonction de l'exposant, celle-ci est calculée en fonction de la position de la souris
* La `Mandelbar` (ou aussi connu sous le nom `Tricorn`) et ses dérivées en fonction de l'exposant
* Le `Burning Ship`
* La `Celtic`
* Le `Mandeldrop` et ses dérivées en fonction de l'exposant

### Contrôles clavier & souris
Pour utiliser `fractol` vous avez à disposition une liste de touches et d'intéractions possibles via le clavier et la souris.

* Déplacements -> *flèches directionnelles haut / bas / gauche / droite*
* Zoom avant sur curseur de la souris -> *`molette avant ou clic gauche de la souris`*
* Zoom arrière sur curseur de la souris -> *`molette arrière ou clic droit de la souris`*
* Zoom général avant -> *`pavé numérique +`*
* Zoom général arrière -> *`pavé numérique -`*
* Changement de la palette de couleur -> *`1 2 3 4 5 6 7 8`*
* Changement de fractale -> *`pavé numérique 0 1 2 3 4 5`*
* Augmenter le nombre d'itérations-> *`PAGE_UP`*
* Diminuer le nombre d'itérations-> *`HOME`*
* Augmenter l'exposant (selon fractale) -> *`pavé numérique *`*
* Diminuer l'exposant (selon fractale) -> *`pavé numérique /`*
* Remise à zéro et recentrage de l'image -> *`R`*
* Remise à zéro des coefficients de couleur -> *`T`*
* Augmenter coefficient de couleur A (palettes 7 et 8) -> *`F13`*
* Diminuer coefficient de couleur A (palettes 7 et 8) -> *`DEL`*
* Augmenter coefficient de couleur B (palettes 7 et 8) -> *`F14`*
* Diminuer coefficient de couleur B (palettes 7 et 8) -> *`END`*
* Augmenter coefficient de couleur C (palettes 7 et 8) -> *`F15`*
* Diminuer coefficient de couleur C (palettes 7 et 8) -> *`PAGE_DOWN`*
* Augmenter coefficient de couleur S (palette 8) -> *`F17`*
* Diminuer coefficient de couleur S (palette 8) -> *`F16`*
* Activer/Désactiver le HUD -> *`H`*
* Activer/Désactiver les guides -> *`G`*
* Quitter le programme -> *`Q` ou `ESC`*

### Palettes de couleurs
Certaines palettes de couleurs peuvent avoir leurs teintes modulées via les différents coefficients de couleur `A B C` ou `S` ou suivant le nombre d'itérations choisi pour les calculs.

La palette `numéro 7` utilise les coefficients `A B` et `C`.

La palette `numéro 8` utilise les coefficients `A B C` et `S`, ce dernier sert pour calculer les orbites tronquées servant pour le calcul du rendu de cette palette.

### Le HUD
Le `HUD` va permettre d'afficher un certain nombre d'informations permettant de contrôler les valeurs des options du programme. De haut en bas dans l'ordre il est affiché:
* Le nom de la fractale
* Le nombre d'itérations utilisé pour les calculs
* Le facteur de zoom
* Les coordonnées en abscisse de la souris en fonction de l'écran et du plan complexe
* Les coordonnées en ordonnée de la souris en fonction de l'écran et du plan complexe
* Le numéro de la palette utilisée
* L'exposant utilisé pour les calculs des fractales pouvant être modulées

## Auteur
`F.MESSINA` étudiant à [`42 Paris`](http://www.42.fr)
## License
[![Image](http://unlicense.org/pd-icon.png)	UNLICENSE](http://unlicense.org/)
