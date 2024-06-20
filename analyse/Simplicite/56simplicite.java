package iut.sae.algo;

public class Algo {
    public static String RLE(String in) {
        if (in.isEmpty() || in == null) {
            return "";
        }

        String resultat = "";
        char caracPrecedent = in.charAt(0);
        int nbChar = 1;
        char caracActuel = 'a';
        for (int i = 1; i < in.length(); i++) {
            caracActuel = in.charAt(i);
            if (caracActuel == caracPrecedent) {
                nbChar++;
                if (nbChar == 10) {
                    resultat +=  9 + caracPrecedent;
                    nbChar = 1;
                }
            } else {
                resultat += "" + nbChar + caracPrecedent;
                nbChar = 1;
                caracPrecedent = caracActuel;
            }
        }
        return (resultat + nbChar + caracActuel);

    }

    public static String RLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) {
            throw new AlgoException("Il faut que l'itération soit au moins égal à 1");
        }
        if (iteration == 1) {
            return RLE(in);
        }
        return RLE(RLE(in, iteration - 1));

    }

    public static String unRLE(String in) throws AlgoException {
        if (in == "" || in == null) {
            return "";
        }
        String resultat = "";
        for (int i = 0; i < in.length(); i += 2) {
            int valeur = Character.getNumericValue(in.charAt(i));
            if (valeur > 9) {
                throw new AlgoException("Erreur : l'argument n'est pas compressé");
            }
            for (int j = 0; j < valeur; j++) {
                resultat += "" + in.charAt(i + 1);
            }
        }
        return resultat;

    }

    public static String unRLE(String in, int iteration) throws AlgoException {
        if (iteration < 1) {
            throw new AlgoException("Il faut que l'itération soit au moins égal à 1");
        }
        if (iteration == 1) {
            return unRLE(in);
        }
        try {

            return unRLE(unRLE(in, iteration - 1));

        } catch (AlgoException a) {
            throw new AlgoException(""+a);
        }
    }
}
