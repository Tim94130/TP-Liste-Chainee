#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Compteur de maillons vivants, interne au module */
static int blocs = 0;

int liste_blocs_en_circulation(void)
{
    return blocs;
}

static Maillon *creer_maillon(int valeur, Maillon *suivant)
{
    Maillon *m = malloc(sizeof(Maillon));
    if (m == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    blocs++;
    m->valeur = valeur;
    m->suivant = suivant;
    return m;
}

Maillon *liste_inserer(Maillon *tete, int valeur)
{
    return creer_maillon(valeur, tete);
}

int liste_longueur(const Maillon *tete)
{
    int n = 0;
    for (const Maillon *m = tete; m != NULL; m = m->suivant) n++;
    return n;
}

bool liste_contient(const Maillon *tete, int valeur)
{
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        if (m->valeur == valeur) return true;
    return false;
}

bool liste_maximum(const Maillon *tete, int *resultat)
{
    if (tete == NULL) return false;

    int max = tete->valeur;
    for (const Maillon *m = tete->suivant; m != NULL; m = m->suivant)
        if (m->valeur > max) max = m->valeur;

    *resultat = max;
    return true;
}

void liste_afficher(const Maillon *tete)
{
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        printf("%d -> ", m->valeur);
    printf("NULL\n");
}

void liste_liberer(Maillon *tete)
{
    while (tete != NULL) {
        Maillon *suiv = tete->suivant;
        free(tete);
        blocs--;
        tete = suiv;
    }
}
