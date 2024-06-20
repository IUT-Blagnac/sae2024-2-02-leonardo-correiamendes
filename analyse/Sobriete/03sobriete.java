package iut.sae.algo;

/*
 * Cette classe fournit des méthodes pour effectuer le codage et le décodage par la méthode Run-Length Encoding (RLE) sur des chaînes de caractères.
 */
public class Sobriete {
    /**
     * Effectue le codage sur une chaîne de caractères donnée.
     *
     * @param in la chaîne d'entrée 
     * @return   la chaîne encodée 
     */
    public static String RLE(String in) {
        if (in == null || in.isEmpty()) {
            return "";
        }

        StringBuilder res = new StringBuilder();
        int count = 1;
        char actuel = in.charAt(0);

        for (int i = 1; i < in.length(); i++) {
            if (in.charAt(i) == actuel) {
                count++;
            } else {
                while (count > 9) {
                    res.append("9").append(actuel);
                    count -= 9;
                }
                res.append(count).append(actuel);
                actuel = in.charAt(i);
                count = 1;
            }
        }

        while (count > 9) {
            res.append("9").append(actuel);
            count -= 9;
        }
        res.append(count).append(actuel);

        return res.toString();
    }

    /**
     * Effectue le codage sur une chaîne de caractères donnée de manière itérative un nombre de fois spécifié.
     *
     * @param in             l'entrée à coder
     * @param iteration      le nombre d'itérations pour appliquer RLE de manière itérative
     * @return               la chaîne encodée de manière itérative
     * @throws AlgoException si la chaîne d'entrée est nulle ou vide
     */
    public static String RLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) {
            throw new AlgoException("The number of iterations must be at least 1");
        }
        for (int i = 0; i < iteration; i++) {
            in = RLE(in);
        }
        return in;
    }

    /**
     * Décode une chaîne encodée précédemment.
     *
     * @param in             la chaîne encodée 
     * @return               la chaîne originale décodée
     * @throws AlgoException si la chaîne d'entrée est nulle ou vide
     */
    public static String unRLE(String in) throws AlgoException {
        if (in == null || in.isEmpty()) {
            return "";
        }

        StringBuilder res = new StringBuilder();
        StringBuilder comte = new StringBuilder();

        for (char c : in.toCharArray()) {
            if (Character.isDigit(c)) {
                comte.append(c);
            } else {
                if (comte.length() == 0) {
                    throw new AlgoException("Invalid string");
                }
                int count = Integer.parseInt(comte.toString());
                for (int i = 0; i < count; i++) {
                    res.append(c);
                }
                comte.setLength(0);
            }
        }

        if (comte.length() > 0) {
            throw new AlgoException("Invalid string");
        }
        return res.toString();
    }

    /**
     * Décode une chaîne encodée de manière itérative un nombre de fois spécifié.
     *
     * @param in             la chaîne encodée itérativement
     * @param iteration      le nombre d'itérations pour appliquer le décodage de manière itérative
     * @return               la chaîne originale décodée de manière itérative
     * @throws AlgoException si la chaîne d'entrée est nulle ou vide
     */
    public static String unRLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) {
            throw new AlgoException("The number of iterations must be at least 1");
        }
        for (int i = 0; i < iteration; i++) {
            in = unRLE(in);
        }
        return in;
    }
}