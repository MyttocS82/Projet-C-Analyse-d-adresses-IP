#include <stdio.h>
#include "Fonctions.h"

int main() {
    char AdresseIP[18];
    int AdresseDecomp[4], MasqueDecomp[4];
    int AdresseReseau[4], AdresseHote[4];

    // Demande à l'utilisateur de saisir une adresse IP
    printf("Saisir l'adresse IP : ");
    scanf("%s", AdresseIP);

    // Affiche l'adresse IP saisie
    printf("\nAdresse saisie : ");
    for (int i = 0; i < 18; i++) {
        printf("%c", AdresseIP[i]);
    }

    // Vérifie si l'adresse IP est valide
    if (verificationIP(AdresseIP) == 1) {
        printf("\n\nAdresse Valide ! \n");

        // Extrait l'adresse IP et le masque de sous-réseau
        extractIP(AdresseIP, AdresseDecomp, MasqueDecomp);

        // Obtient et affiche la classe de l'adresse IP
        char classe = obtenirClasse(AdresseDecomp);
        printf("\nLa classe de l'adresse reseau est : %c\n", classe);

        // Détermine et affiche le type de l'adresse IP
        const char* type = typeIP(AdresseDecomp);
        printf("Le type de l'adresse IP est : %s\n", type);

        // Calcule et affiche l'adresse réseau
        calculReseau(AdresseDecomp, MasqueDecomp, AdresseReseau);
        calculHote(AdresseDecomp, MasqueDecomp, AdresseHote);

        printf("\nAdresse Hote :\n");
        for (int i = 0; i < 4; i++) {
            printf("%d ", AdresseHote[i]);
        }

        printf("\n\nAdresse reseau :\n");
        for (int i = 0; i < 4; i++) {
            printf("%d ", AdresseReseau[i]);
        }
    } else {
        // Affiche un message d'erreur si l'adresse IP est invalide
        printf("\nAdresse invalide ! \n");
    }

    return 0;
}
