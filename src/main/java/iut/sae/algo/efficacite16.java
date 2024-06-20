package iut.sae.algo;

// 16efficacite
// Compile V
// Anonyme
// Java Util V
// Fonctionne V
// Passe les tests V
// Passe tous les tests V
// Passe mes tests V
// Noté sur 20

/** 
 * Classe contenant les algorithmes de compression et décompression RLE
 * <BR>
 * IUT de Blagnac - Université Toulouse II - Jean Jaurès
 * S2.02 - Exploration algorithmique d'un problème
 * Année universitaire 2023-2024
 */
public class efficacite16 {

    /**
     * Compresse une chaîne de caractères en utilisant l'algorithme RLE.
     *
     * @param in La chaîne de caractères à compresser.
     * @return La chaîne de caractères compressée.
     * @throws IllegalArgumentException Si la chaîne d'entrée est nulle.
     *
     * Complexité : O(n) où n est la longueur de la chaîne d'entrée.
     *
     * La méthode parcourt la chaîne d'entrée une seule fois, ce qui assure une complexité linéaire.
     * La boucle principale s'exécute en O(n) et chaque opération à l'intérieur de la boucle est O(1).
     */
    public static String RLE(String in) {
        if (in == null) throw new IllegalArgumentException("La chaîne d'entrée ne peut pas être nulle");
        if (in.isEmpty()) return "";

        StringBuilder resultats = new StringBuilder();
        int compteur = 1;
        char caractereCourant = in.charAt(0);

        for (int i = 1; i < in.length(); i++) {
            if (in.charAt(i) == caractereCourant) {
                compteur++;
                if (compteur == 9) {
                    resultats.append(9).append(caractereCourant);
                    compteur = 0;
                }
            } else {
                if (compteur > 0) {
                    resultats.append(compteur).append(caractereCourant);
                }
                caractereCourant = in.charAt(i);
                compteur = 1;
            }
        }

        if (compteur > 0) {
            resultats.append(compteur).append(caractereCourant);
        }

        return resultats.toString();
    }

    /**
     * Compresse une chaîne de caractères en utilisant l'algorithme RLE sur plusieurs itérations.
     *
     * @param in La chaîne de caractères à compresser.
     * @param iteration Le nombre d'itérations de compression.
     * @return La chaîne de caractères compressée après le nombre d'itérations spécifié.
     * @throws AlgoException Si le nombre d'itérations est inférieur à 1.
     * @throws IllegalArgumentException Si la chaîne d'entrée est nulle.
     *
     * Complexité : O(n * k) où n est la longueur de la chaîne d'entrée et k le nombre d'itérations.
     *
     * Cette version utilise une boucle au lieu de la récursivité pour éviter une consommation excessive de la pile
     * d'appels (stack overflow) et améliorer l'efficacité en termes de gestion de la mémoire.
     */
    public static String RLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) throw new AlgoException("L'itération doit être supérieure à 0");
        if (in == null) throw new IllegalArgumentException("La chaîne d'entrée ne peut pas être nulle");

        String resultat = in;
        for (int i = 0; i < iteration; i++) {
            resultat = RLE(resultat);
        }

        return resultat;
    }

    /**
     * Décompresse une chaîne de caractères en utilisant l'algorithme RLE sur plusieurs itérations.
     *
     * @param in La chaîne de caractères à décompresser.
     * @param iteration Le nombre d'itérations de décompression.
     * @return La chaîne de caractères décompressée après le nombre d'itérations spécifié.
     * @throws AlgoException Si le nombre d'itérations est inférieur à 1.
     * @throws IllegalArgumentException Si la chaîne d'entrée est nulle.
     *
     * Complexité : O(n * k) où n est la longueur de la chaîne d'entrée et k le nombre d'itérations.
     *
     * Cette version utilise une boucle au lieu de la récursivité pour éviter une consommation excessive de la pile
     * d'appels (stack overflow) et améliorer l'efficacité en termes de gestion de la mémoire.
     */
    public static String unRLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) throw new AlgoException("L'itération doit être supérieure à 0");
        if (in == null) throw new IllegalArgumentException("La chaîne d'entrée ne peut pas être nulle");

        String resultat = in;
        for (int i = 0; i < iteration; i++) {
            resultat = unRLE(resultat);
        }
        return resultat;
    }

    /**
     * Décompresse une chaîne de caractères en utilisant l'algorithme RLE.
     *
     * @param in La chaîne de caractères à décompresser.
     * @return La chaîne de caractères décompressée.
     * @throws AlgoException Si la chaîne d'entrée est invalide.
     * @throws IllegalArgumentException Si la chaîne d'entrée est nulle.
     *
     * Complexité : O(n) où n est la longueur de la chaîne d'entrée.
     *
     * La méthode parcourt la chaîne d'entrée une seule fois, ce qui assure une complexité linéaire.
     * La boucle principale s'exécute en O(n) et chaque opération à l'intérieur de la boucle est O(1).
     */
    public static String unRLE(String in) throws AlgoException {
        if (in == null) throw new IllegalArgumentException("La chaîne d'entrée ne peut pas être nulle");
        if (in.length() % 2 != 0) throw new AlgoException("Longueur d'entrée invalide");
        if (in.isEmpty()) return "";

        StringBuilder sortie = new StringBuilder();
        for (int i = 0; i < in.length(); i += 2) {
            char charCompteur = in.charAt(i);
            char caractere = in.charAt(i + 1);

            if (!Character.isDigit(charCompteur)) throw new AlgoException("Le caractère de comptage doit être un chiffre");

            int compteur = Character.getNumericValue(charCompteur);

            if (compteur <= 0) throw new AlgoException("Le compteur doit être supérieur à zéro");

            if (!(caractere >= 32 && caractere <= 126)) throw new AlgoException("Caractère invalide rencontré : " + caractere);

            sortie.append(String.valueOf(caractere).repeat(compteur));
        }
        return sortie.toString();
    }
}
