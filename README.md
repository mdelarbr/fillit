V.1 L’entrée du programme

Votre exécutable doit prendre en paramètre un (et un seul) fichier décrivant la liste
des Tetriminos à agencer. Ce fichier est formaté de façon très précise : chaque description
d’un Tetriminos est sur 4 lignes et deux Tetriminos sont séparés par une ligne vide.
Si le nombre de paramètres passés à votre exécutable est différent de 1, votre programme doit afficher son usage et quitter proprement. Si vous ignorez ce qu’est un usage,
lancez la commande cp sans argument dans votre shell pour vous faire une idée. Il n’y
aura jamais plus de 26 Tetriminos dans un fichier de description.
La description d’un Tetrimino doit respecter les règles suivantes :

• Exactement 4 lignes de 4 caractères suivis d’un retour à la ligne.

• Un Tetriminos est une pièce de Tetris classique composée de 4 blocs.

• Chaque caractère doit être, soit un ’#’ lorsque la case correspond à l’un des 4
blocs d’un Tetriminos, soit un ’.’ lorsque la case est vide.

• Chaque bloc d’un Tetriminos doit être en contact avec au moins un autre bloc
sur l’un ou l’autre de ses 4 côtés.

Quelques exemples de descriptions de Tetriminos valides :

.... .... #### .... .##. .... .#.. .... ....
..## .... .... .... ..## .##. ###. ##.. .##.
..#. ..## .... ##.. .... ##.. .... #... ..#.
..#. ..## .... ##.. .... .... .... #... ..#.

Quelques exemples de descriptions de Tetriminos invalides :

#### ...# ##... #. .... ..## #### ,,,, .HH.
...# ..#. ##... ## .... .... #### #### HH..
.... .#.. .... #. .... .... #### ,,,, ....
.... #... .... .... ##.. #### ,,,, ....

Chaque Tetriminos n’occupant que 4 cases des 16 cases disponibles, il est donc possible de décrire le même Tetriminos de plusieurs façons différentes. Toutefois, la rotation
d’un Tetriminos décrit un Tetriminos différent de l’original dans le cadre de ce projet.
Cela signifie qu’aucune rotation n’est possible sur un Tetriminos lorsque vous l’agencerez par rapport aux autres.

Ces Tetriminos sont donc parfaitement équivalents à tous points de vue :

##.. .##. ..## .... .... ....
#... .#.. ..#. ##.. .##. ..##
#... .#.. ..#. #... .#.. ..#.
.... .... .... #... .#.. ..#.

Ces 5 Tetriminos sont, quand à eux, 5 Tetriminos parfaitement distincts à tous
points de vue :

##.. .### .... .... ....
#... ...# ...# .... .##.
#... .... ...# #... .##.
.... .... ..## ###. ....

Pour terminer, voici un exemple de fichier de description valide que votre programme
doit accepter de résoudre,

$> cat -e valid_sample.fillit
...#$
...#$
...#$
...#$
$
....$
....$
....$
####$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$>

Ainsi qu’un exemple de fichier de description invalide que votre programme doit rejeter pour plusieurs raisons :

$> cat -e invalid_sample.fillit
...#$
...#$
...#$
...#$
....$
....$
....$
####$
$
$
.###$
...#$
....$
....$
$
....$
..##$
.##.$
....$
$
$>

V.2 Le plus petit carré

Le but de ce projet est d’agencer les Tetriminos entre eux pour former le plus petit
carré possible, sachant que ce carré peut présenter des trous quand les pièces données ne
s’emboîtent pas parfaitement.
Chaque Tetriminos, bien que présenté sur une grille de 16 cases, n’est défini que
par ses cases pleines (ses ’#’). Les 12 ’.’ restants sont ignorés pour l’agencement des
Tetriminos entre eux.
Les Tetriminos sont placés dans l’ordre dans lequel ils apparaissent dans le fichier.
Parmi les différentes solutions possibles réalisant le plus petit carré, sera retenue la solution où chaque Tetriminos est disposé le plus en haut, puis le plus à gauche possible, au
moment de son placement.
Exemple :

Considèrons les deux Tetriminos suivants (les ’#’ sont remplacés par des chiffres
pour simplifier la lecture des resulats) :
1... ....
1... ....
1... ET ..22
1... ..22

Le plus petit carré formé par ces 2 pièces fait 4 cases de coté, mais il en existe plusieurs
versions que vous pouvez voir ci-dessous :
a) b) c) d) e) f)
122. 1.22 1... 1... 1... 1...
122. 1.22 122. 1.22 1... 1...
1... 1... 122. 1.22 122. 1.22
1... 1... 1... 1... 122. 1.22

g) h) i) j) k) l)
.122 .1.. .1.. 221. ..1. ..1.
.122 .122 .1.. 221. 221. ..1.
.1.. .122 .122 ..1. 221. 221.
.1.. .1.. .122 ..1. ..1. 221.

m) n) o) p) q) r)
22.1 .221 ...1 ...1 ...1 ...1
22.1 .221 22.1 .221 ...1 ...1
...1 ...1 22.1 .221 22.1 .221
...1 ...1 ...1 ...1 22.1 .221
D’après les règles du jeu, la bonne solution est donc a).

V.3 La sortie du programme

Votre programme doit afficher le plus petit carré solution sur la sortie standard. Pour
pouvoir identifier chaque Tetriminos dans le carré solution, vous assignerez une lettre
majuscule (en commencant avec ’A’) à ce Tetriminos dans l’ordre où ils apparaissent
dans le fichier de description.
Si le fichier de description comporte au moins une erreur, votre programme doit afficher error sur la sortie standard et quitter proprement.
Exemple :
$> cat sample.fillit | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$

$> ./fillit sample.fillit | cat -e
DDAA$
CDDA$
CCCA$
BBBB$
$>
Autre Exemple :
$> cat sample.fillit | cat -e
....$
....$
####$
....$
$
....$
...$
..##$
..##$
$> ./fillit sample.fillit | cat -e
error$
$>
