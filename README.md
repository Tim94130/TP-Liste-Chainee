# TP – Liste chaînée en C

Liste chaînée simple d'entiers, avec un compteur de maillons pour détecter les fuites mémoire.
## Fichiers

| Fichier | Rôle |
|---|---|
| `liste.h` / `liste.c` | La bibliothèque de liste chaînée |
| `main.c` | Programme de test (affiche `OK` / `ECHEC` pour chaque vérification) |
| `Makefile` | Compilation |

## Utilisation

```sh
make        # compile -> ./demo
make run    # compile et lance les tests
make clean  # supprime les fichiers générés
```

## Fonctions

| Fonction | Description |
|---|---|
| `liste_inserer` | Insère en tête |
| `liste_inserer_fin` | Insère en queue |
| `liste_supprimer` | Supprime la première occurrence d'une valeur |
| `liste_inverser` | Inverse la liste sur place |
| `liste_longueur` | Nombre de maillons |
| `liste_contient` | Recherche d'une valeur |
| `liste_somme` | Somme des valeurs |
| `liste_minimum` / `liste_maximum` | Plus petite / plus grande valeur (`false` si liste vide) |
| `liste_afficher` | Affiche `a -> b -> NULL` |
| `liste_liberer` | Libère toute la liste |
| `liste_blocs_en_circulation` | Maillons alloués non libérés (doit valoir 0 à la fin) |

Les fonctions qui modifient la liste renvoient la **nouvelle tête** : `liste = liste_inserer(liste, 42);`
