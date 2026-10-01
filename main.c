#include <stdio.h>
#include "liste.h"

static int echecs = 0;

/* Verifie une condition et affiche OK / ECHEC */
static void verifier(const char *description, bool condition)
{
    printf("  [%s] %s\n", condition ? "OK" : "ECHEC", description);
    if (!condition) echecs++;
}

int main(void)
{
    Maillon *liste = NULL;
    int val;

    printf("== Insertion ==\n");
    for (int i = 1; i <= 5; i++) liste = liste_inserer(liste, i * 10);
    liste = liste_inserer_fin(liste, 5);
    liste_afficher(liste);
    verifier("longueur = 6", liste_longueur(liste) == 6);
    verifier("contient 30", liste_contient(liste, 30));
    verifier("ne contient pas 99", !liste_contient(liste, 99));

    printf("== Statistiques ==\n");
    verifier("somme = 155", liste_somme(liste) == 155);
    verifier("minimum = 5", liste_minimum(liste, &val) && val == 5);
    verifier("maximum = 50", liste_maximum(liste, &val) && val == 50);
    verifier("minimum d'une liste vide = false", !liste_minimum(NULL, &val));

    printf("== Suppression ==\n");
    liste = liste_supprimer(liste, 50);   /* la tete */
    liste = liste_supprimer(liste, 5);    /* la queue */
    liste = liste_supprimer(liste, 99);   /* absent : ne change rien */
    liste_afficher(liste);
    verifier("longueur = 4", liste_longueur(liste) == 4);
    verifier("50 supprime", !liste_contient(liste, 50));

    printf("== Inversion ==\n");
    liste = liste_inverser(liste);
    liste_afficher(liste);
    verifier("nouvelle tete = 10", liste->valeur == 10);

    printf("== Liberation ==\n");
    liste_liberer(liste);
    verifier("aucune fuite memoire", liste_blocs_en_circulation() == 0);

    printf("\n%s\n", echecs == 0 ? "Tous les tests passent." : "Des tests ont echoue.");
    return echecs == 0 ? 0 : 1;
}
