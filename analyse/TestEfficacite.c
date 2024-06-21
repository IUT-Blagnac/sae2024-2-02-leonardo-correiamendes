// Bout de code avec lequel j'ai fais les test pour les programme en C (sur Replit)
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

int main() {
  
  char* test = RLE("");

  // RLE 
  
  if(strcmp(test, "") == 0) {
    printf("Test 1 RLE passé\n");
  } else {
    printf("Test 1 RLE non passé\n");
  }

  test = RLE("abc");
  if(strcmp(test, "1a1b1c") == 0) {
  printf("Test 2 RLE passé\n");
  } else {
    printf("Test 2 RLE non passé\n");
  }

  test = RLE("abbccc");
  if(strcmp(test, "1a2b3c") == 0) {
  printf("Test 3 RLE passé\n");
  } else {
    printf("Test 3 RLE non passé\n");
  }

  test = RLE("aaabaa");
  if(strcmp(test, "3a1b2a") == 0) {
  printf("Test 4 RLE passé\n");
  } else {
    printf("Test 4 RLE non passé\n");
  }

  test = RLE("aAa");
  if(strcmp(test, "1a1A1a") == 0) {
  printf("Test 5 RLE passé\n");
  } else {
    printf("Test 5 RLE non passé\n");
  }

  test = RLE("WWWWWWWWWWWWW");
  if(strcmp(test, "9W4W") == 0) {
  printf("Test 6 RLE passé\n");
  } else {
    printf("Test 6 RLE non passé\n");
  }

  // RLE R

  test = RLE_recursif("", 1);
  if(strcmp(test, "") == 0) {
  printf("Test 1 RLER passé\n");
  } else {
    printf("Test 1 RLER non passé\n");
  }

  test = RLE_recursif("", 3);
  if(strcmp(test, "") == 0) {
  printf("Test 2 RLER passé\n");
  } else {
    printf("Test 2 RLER non passé\n");
  }

  test = RLE_recursif("abc", 1);
  if(strcmp(test, "1a1b1c") == 0) {
  printf("Test 3 RLER passé\n");
  } else {
    printf("Test 3 RLER non passé\n");
  }

  test = RLE_recursif("abbccc", 1);
  if(strcmp(test, "1a2b3c") == 0) {
  printf("Test 4 RLER passé\n");
  } else {
    printf("Test 4 RLER non passé\n");
  }

  test = RLE_recursif("aaabaa", 1);
  if(strcmp(test, "3a1b2a") == 0) {
  printf("Test 5 RLER passé\n");
  } else {
    printf("Test 5 RLER non passé\n");
  }

  test = RLE_recursif("aAc", 1);
  if(strcmp(test, "1a1A1a") == 0) {
  printf("Test 6 RLER passé\n");
  } else {
    printf("Test 6 RLER non passé\n");
  }

  test = RLE_recursif("abc", 2);
  if(strcmp(test, "111a111b111c") == 0) {
  printf("Test 7 RLER passé\n");
  } else {
    printf("Test 7 RLER non passé\n");
  }

  test = RLE_recursif("abc", 3);
  if(strcmp(test, "311a311b311c") == 0) {
  printf("Test 8 RLER passé\n");
  } else {
    printf("Test 8 RLER non passé\n");
  }

  // unRLE

  test = unRLE("");
  if(strcmp(test, "") == 0) {
  printf("Test 1 unRLE passé\n");
  } else {
  printf("Test 1 unRLE échoué\n");
  }

  test = unRLE("1a1b1c");
  if(strcmp(test, "abc") == 0) {
  printf("Test 2 unRLE passé\n");
  } else {
  printf("Test 2 unRLE échoué\n");
  }

  test = unRLE("1a2b3c");
  if(strcmp(test, "abbccc") == 0) {
  printf("Test 3 unRLE passé\n");
  } else {
  printf("Test 3 unRLE échoué\n");
  }

  test = unRLE("3a1b2a");
  if(strcmp(test, "aaabaa") == 0) {
  printf("Test 4 unRLE passé\n");
  } else {
  printf("Test 4 unRLE échoué\n");
  }

  test = unRLE("1a1A1a");
  if(strcmp(test, "aAa") == 0) {
  printf("Test 5 unRLE passé\n");
  } else {
  printf("Test 5 unRLE échoué\n");
  }

  test = unRLE("9W4W");
  if(strcmp(test, "WWWWWWWWWWWWW") == 0) {
  printf("Test 6 unRLE passé\n");
  } else {
  printf("Test 6 unRLE échoué\n");
  }

  // unRLER

  test = unRLE_recursif("", 1);
  if(strcmp(test, "") == 0) {
  printf("Test 1 unRLER passé\n");
  } else {
  printf("Test 1 unRLER échoué\n");
  }

  test = unRLE_recursif("", 3);
  if(strcmp(test, "") == 0) {
  printf("Test 2 unRLER passé\n");
  } else {
  printf("Test 2 unRLER échoué\n");
  }

  test = unRLE_recursif("1a1b1c", 1);
  if(strcmp(test, "abc") == 0) {
  printf("Test 3 unRLER passé\n");
  } else {
  printf("Test 3 unRLER échoué\n");
  }

  test = unRLE_recursif("1a2b3c", 1);
  if(strcmp(test, "abbccc") == 0) {
  printf("Test 4 unRLER passé\n");
  } else {
  printf("Test 4 unRLER échoué\n");
  }

  test = unRLE_recursif("3a1b2a", 1);
  if(strcmp(test, "aaabaa") == 0) {
  printf("Test 5 unRLER passé\n");
  } else {
  printf("Test 5 unRLER échoué\n");
  }

  test = unRLE_recursif("1a1A1a", 1);
  if(strcmp(test, "aAa") == 0) {
  printf("Test 6 unRLER passé\n");
  } else {
  printf("Test 6 unRLER échoué\n");
  }

  test = unRLE_recursif("111a111b111c", 2);
  if(strcmp(test, "abc") == 0) {
  printf("Test 7 unRLER passé\n");
  } else {
    printf("Test 7 unRLER échoué\n");
    }

  test = unRLE_recursif("311a311b311c", 3);
  if(strcmp(test, "abc") == 0) {
  printf("Test 8 unRLER passé\n");
  } else {
    printf("Test 8 unRLER échoué\n");
    }
  
  return 0;
}