#ifndef CODE_FONCTIONS_H
#define CODE_FONCTIONS_H

int verificationIP(char *ip);
void extractIP(char *ip, int parties[], int MaskP[]);
char obtenirClasse(int parties[]);
const char* typeIP(int parties[]);
void calculReseau(int parties[], int mask[], int NetAddress[]);
void calculHote(int parties[], int mask[], int HostAddress[]);

#endif //CODE_FONCTIONS_H
