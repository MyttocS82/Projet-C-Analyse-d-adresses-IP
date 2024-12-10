#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Fonctions.h"

// Vérifie si l'adresse IP et le masque sont valides
int verificationIP(char *ip) {
    int parties[4], masque[4];
    int testeur = 0;

    extractIP(ip, parties, masque);
    for (int i = 0; i < 4; i++) {
        if (parties[i] >= 0 && parties[i] <= 255 && masque[i] >= 0 && masque[i] <= 255) {
            testeur++;
        }
    }

    int numMasque = 0;
    char *slash = strchr(ip, '/');
    if (slash) {
        sscanf(slash + 1, "%d", &numMasque);
    }
    if (numMasque >= 0 && numMasque <= 32) {
        testeur++;
    }

    if (testeur == 5) {
        return 1;
    } else {
        return 0;
    }
}

// Extrait les parties de l'adresse IP et le masque de sous-réseau
void extractIP(char *ip, int parties[], int MaskP[]) {
    sscanf(ip, "%d.%d.%d.%d", &parties[0], &parties[1], &parties[2], &parties[3]);

    int numMasque = 0;
    char *slash = strchr(ip, '/');
    if (slash) {
        sscanf(slash + 1, "%d", &numMasque);
    }

    for (int i = 0; i < 4; i++) {
        if (numMasque >= 8) {
            MaskP[i] = 255;
            numMasque -= 8;
        } else if (numMasque > 0) {
            MaskP[i] = (uint8_t) (255 - (1 << (8 - numMasque)));
            numMasque = 0;
        } else {
            MaskP[i] = 0;
        }
    }
}

// Détermine la classe de l'adresse IP (A, B, C, D, E)
char obtenirClasse(int parties[]) {
    char unknown = 'Z';

    if (parties[0] >= 0 && parties[0] <= 127) {
        return 'A';
    } else if (parties[0] >= 128 && parties[0] <= 191) {
        return 'B';
    } else if (parties[0] >= 192 && parties[0] <= 223) {
        return 'C';
    } else if (parties[0] >= 224 && parties[0] <= 239) {
        return 'D';
    } else if (parties[0] >= 240 && parties[0] <= 255) {
        return 'E';
    } else {
        return unknown;
    }
}

// Détermine le type de l'adresse IP (publique, privée, localhost, broadcast, multicast)
const char* typeIP(int parties[]) {
    if ((parties[0] == 10) ||
        (parties[0] == 172 && parties[1] >= 16 && parties[1] <= 31) ||
        (parties[0] == 192 && parties[1] == 168)) {
        return "Privee";
    }

    if (parties[0] == 127) {
        return "Localhost";
    }

    if (parties[3] == 255) {
        return "Broadcast";
    }

    if (parties[0] >= 224 && parties[0] <= 239) {
        return "Multicast";
    }

    return "Publique";
}

// Calcule l'adresse réseau
void calculReseau(int parties[], int mask[], int NetAddress[]) {
    for (int i = 0; i < 4; i++) {
        NetAddress[i] = parties[i] & mask[i];
    }
}

// Calcule l'adresse hôte
void calculHote(int parties[], int mask[], int HostAddress[]) {
    for (int i = 0; i < 4; i++) {
        HostAddress[i] = parties[i] & ~mask[i];
    }
}
