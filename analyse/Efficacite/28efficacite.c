#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h> // librairie des tests
#include <time.h> // librairie pour tester le temps d'exécution

/* Attention le nom de la seconde méthode récursive change car la surcharge de méthode n'est pas possible en C */

char* RLE(char* in) {
    
    if (strcmp(in, "") == 0) { // compare in et "" et revoie 0 si les chaînes sont identiques
        return ""; // alloue de la mémoire, copie "" et retourne un pointeur
    }
    
    int cptC = 1; // compteur de caractères
    int sizeChaineIn = strlen(in); // taille chaîne en entrée

    // sizeChaineIn * 2 c'est le cas le plus élevé possible (chaque lettre est unique) et +1 pour le caractère de fin de chaîne (\0)
    char* chaineCompressee = malloc(sizeChaineIn * 2 + 1); 
    int dernierePosEcriture = 0; // dernière position d'écriture dans la chaîne compressée
    // on fait += dernierPosEcriture, car la fonction sprintf retourne le nombre de caractères qu'elle vient de concaténer
    // pour ne pas perdre la position d'écriture on fait +=
    // on fait chaineCompressee + dernierPosEcriture car en C, lorsqu'on ajoute un entier à un pointeur on va à la position du pointeur + l'entier, donc on sera sur la bonne position d'écriture
    
    // parcours de la chaîne en entrée
    for (int i = 0; i < sizeChaineIn; i++) {
        if (i != sizeChaineIn - 1) {
            // cas usuels (si je ne suis pas à la dernière lettre)
            if (in[i] == in[i + 1]) {
                cptC++;
                // limiter à des paquets de 9
                if (cptC == 9) {
                    dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]); // %d pour int et %c pour le caractère
                    cptC = 1;
                    i++; // régler le décalage des paquets de 9 (parce qu'on regarde le i + 1 dans la comparaison de char)
                }
            } else {
                dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]);
                cptC = 1;
            }
        } else {
            // cas de la dernière lettre
            dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]);
        }
    }
    // redimensionner la chaîne compressée à la dernière position d'écriture + 1 pour le caractère de fin de chaîne (\0)
    chaineCompressee = realloc(chaineCompressee, dernierePosEcriture + 1);
    free(in); // libère la mémoire allouée pour la chaîne en entrée
    return chaineCompressee;
}

char* RLE_recursive(char* in, int iteration) {
    
    if (strcmp(in, "") == 0 || iteration == 0) { 
        return in; 
    }

    if (iteration <= 0 ) {
        return "Erreur: l'itération doit être un entier positif";
    }
    
    int cptC = 1; // compteur de caractères
    int sizeChaineIn = strlen(in); // taille chaîne en entrée

    // sizeChaineIn * 2 c'est le cas le plus élevé possible (chaque lettre est unique) et +1 pour le caractère de fin de chaîne (\0)
    char* chaineCompressee = malloc(sizeChaineIn * 2 + 1); 
    int dernierePosEcriture = 0; // dernière position d'écriture dans la chaîne compressée
    // on fait += dernierPosEcriture, car la fonction sprintf retourne le nombre de caractères qu'elle vient de concaténer
    // pour ne pas perdre la position d'écriture on fait +=
    // on fait chaineCompressee + dernierPosEcriture car en C, lorsqu'on ajoute un entier à un pointeur on va à la position du pointeur + l'entier, donc on sera sur la bonne position d'écriture
    
    // parcours de la chaîne en entrée
    for (int i = 0; i < sizeChaineIn; i++) {
        if (i != sizeChaineIn - 1) {
            // cas usuels (si je ne suis pas à la dernière lettre)
            if (in[i] == in[i + 1]) {
                cptC++;
                // limiter à des paquets de 9
                if (cptC == 9) {
                    dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]); // %d pour int et %c pour le caractère
                    cptC = 1;
                    i++; // régler le décalage des paquets de 9 (parce qu'on regarde le i + 1 dans la comparaison de char)
                }
            } else {
                dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]);
                cptC = 1;
            }
        } else {
            // cas de la dernière lettre
            dernierePosEcriture += sprintf(chaineCompressee + dernierePosEcriture, "%d%c", cptC, in[i]);
        }
    }
    // redimensionner la chaîne compressée à la dernière position d'écriture + 1 pour le caractère de fin de chaîne (\0)
    chaineCompressee = realloc(chaineCompressee, dernierePosEcriture + 1);
    free(in); // libère la mémoire allouée pour la chaîne en entrée
    return RLE_recursive(chaineCompressee, iteration - 1);
}
