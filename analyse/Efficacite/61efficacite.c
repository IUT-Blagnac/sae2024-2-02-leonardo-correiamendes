#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* RLE(char* text) {
    // on initialise les variables
    char lettre = text[0];
    int longueurTexte = strlen(text);
    char* chaineFinale = (char*)malloc(longueurTexte * 2 + 1);
    int compteurLettre = 0;
    int indexChaineFinale = 0;
    // on regarde chaque caractère du texte
    for (int i = 0; i < longueurTexte; i++) {
        // Si le caractère est le même que le précédent et que le compteur est inférieur à 9
        if (lettre == text[i] && compteurLettre < 9) {
            // on ajoute 1 au compteur
            compteurLettre++;
        } else {
            // on jaoute le compteur et la lettre à la chaîne finale
            sprintf(chaineFinale + indexChaineFinale, "%d%c", compteurLettre, lettre);
            indexChaineFinale += 2; // a chaque fois, nous on ajoute 2 caractères : un nombre et une lettre
            
            compteurLettre = 1;
            
            lettre = text[i];
        }
        // Si le compteur atteint 9 (il faut pas avoir 13w par exemple)
        if (compteurLettre == 9) {
            // on jaoute direct le compteur et la lettre à la chaîne finale
            sprintf(chaineFinale + indexChaineFinale, "%d%c", compteurLettre, lettre);
            indexChaineFinale += 2;
            // si on n'est pas à la fin de la chaîne
            if (i < longueurTexte - 1) {
                
                lettre = text[i + 1];
            }
            
            compteurLettre = 0;
        }
    }
    // si le compteur est supérieur à 0 à la fin de la boucle
    if (compteurLettre > 0) {
        // on ajoute ce qu'il reste a la chaine finale
        sprintf(chaineFinale + indexChaineFinale, "%d%c", compteurLettre, lettre);
    }
    // on alloue la memoire necessaire a chaineFinale
    chaineFinale = realloc(chaineFinale, indexChaineFinale + 1);
    
    return chaineFinale;
}

// fonction encoder de manière récursive
char* RLE_recursif(const char* chaine, int nombre) {
    char* resultat = strdup(chaine);
    char* temp = NULL;
    for (int i = 0; i < nombre; i++) {
        temp = RLE(resultat);
        free(resultat);
        resultat = temp;
    }
    return resultat;
}

char* unRLE(const char* chaine) {
    int length = strlen(chaine);
    char* result = malloc(length * sizeof(char));
    int index = 0;
    for (int i = 0; i < length; i += 2) {
        int nombre = chaine[i] - '0';
        char caractere = chaine[i + 1];
        for (int j = 0; j < nombre; j++) {
            result[index++] = caractere;
        }
    }
    result[index] = '\0';
    return result;
}

char* unRLE_recursif(const char* chaine, int nombre) {
    char* resultat = strdup(chaine);
    for (int i = 0; i < nombre; i++) {
        char* temp = unRLE(resultat);
        free(resultat);
        resultat = temp;
    }
    return resultat;
}