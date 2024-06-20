#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *RLE(const char *in) {
    if (in == NULL || strlen(in) == 0) {
        return "";
    }

    size_t length = strlen(in);
    char *sortie = (char *)malloc(2 * length + 1);
    if (sortie == NULL) {
        return NULL;
    }

    char char_precedent = in[0];
    int nombre_repetitions = 1;
    char *sortie_intermediaire = sortie;

    for (size_t i = 1; i < length; i++) {
        if (in[i] == char_precedent) {
            if (nombre_repetitions == 9) {
                sortie_intermediaire += sprintf(sortie_intermediaire, "%d%c", nombre_repetitions, char_precedent);
                nombre_repetitions = 1;
            } else {
                nombre_repetitions++;
            }
        } else {
            sortie_intermediaire += sprintf(sortie_intermediaire, "%d%c", nombre_repetitions, char_precedent);
            char_precedent = in[i];
            nombre_repetitions = 1;
        }
    }
    sortie_intermediaire += sprintf(sortie_intermediaire, "%d%c", nombre_repetitions, char_precedent);
    *sortie_intermediaire = '\0';

    return sortie;
}

char *RLE_iterations(const char *in, int iteration) {
    if (iteration <= 0 || in == NULL || strlen(in) == 0) {
        return strdup(in);
    }

    char *sortie = strdup(in);
    if (sortie == NULL) {
        return NULL;
    }

    for (int i = 0; i < iteration; i++) {
        char *temp = RLE(sortie);
        free(sortie);
        sortie = temp;
    }

    return sortie;
}

char *unRLE(const char *in) {
    if (in == NULL || strlen(in) == 0) {
        return "";
    }

    size_t length = strlen(in);
    char *sortie = (char *)malloc(length * 9 + 1);
    if (sortie == NULL) {
        return NULL;
    }

    char *sortie_intermediaire = sortie;

    for (size_t i = 0; i < length; i += 2) {
        int nombre_repetitions = in[i] - '0';
        char char_precedent = in[i + 1];

        for (int j = 0; j < nombre_repetitions; j++) {
            *sortie_intermediaire++ = char_precedent;
        }
    }
    *sortie_intermediaire = '\0';

    return sortie;
}

char *unRLE_iterations(const char *in, int iteration) {
    if (iteration <= 0 || in == NULL || strlen(in) == 0) {
        return strdup(in);
    }

    char *sortie = strdup(in);
    if (sortie == NULL) {
        return NULL;
    }

    for (int i = 0; i < iteration; i++) {
        char *temp = unRLE(sortie);
        free(sortie);
        sortie = temp;
    }

    return sortie;
}