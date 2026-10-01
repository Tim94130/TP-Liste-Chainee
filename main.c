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
    liste_afficher(liste);
    verifier("longueur = 5", liste_longueur(liste) == 5);
    verifier("contient 30", liste_contient(liste, 30));
    verifier("ne contient pas 99", !liste_contient(liste, 99));

    printf("== Statistiques ==\n");
    verifier("maximum = 50", liste_maximum(liste, &val) && val == 50);

    printf("== Liberation ==\n");
    liste_liberer(liste);
    verifier("aucune fuite memoire", liste_blocs_en_circulation() == 0);

    printf("\n%s\n", echecs == 0 ? "Tous les tests passent." : "Des tests ont echoue.");
    return echecs == 0 ? 0 : 1;
}
