#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

typedef struct Maillon {
    int valeur;
    struct Maillon *suivant;
} Maillon;

/* Insertion : renvoie la nouvelle tete */
Maillon *liste_inserer(Maillon *tete, int valeur);       /* en tete */

/* Consultation */
int  liste_longueur(const Maillon *tete);
bool liste_contient(const Maillon *tete, int valeur);
bool liste_maximum(const Maillon *tete, int *resultat);  /* false si liste vide */

void liste_afficher(const Maillon *tete);
void liste_liberer(Maillon *tete);

/* Nombre de maillons alloues et pas encore liberes (detection de fuites) */
int liste_blocs_en_circulation(void);

#endif /* LISTE_H */
