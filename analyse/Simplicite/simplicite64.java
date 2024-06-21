package iut.sae.algo;

// 64simplicite.java
// Compile V
// Anonyme V
// Java Util V
// Fonctionne V
// Passe les tests X
// Passe tous les tests X
// Passe mes tests X
// Noté sur 10 

// Le code est très simple et compréhensible.
// Cependant les tests ne passent pas. Mes tests ne passent pas non plus.
// Je retire 1 point.
// Note : 9/20
// Classement : 4eme

public class simplicite64 {

    public static String RLE(String in) throws AlgoException {
        return RLE(in, 1);
    }

    public static String RLE(String in, int iteration) throws AlgoException {
        if (in == null || in.isEmpty()) {
            return "";
        }

        String result = in;
        for (int iter = 0; iter < iteration; iter++) {
            StringBuilder compressed = new StringBuilder();
            char ch = result.charAt(0);
            int count = 1;

            for (int i = 1; i < result.length(); i++) {
                if (result.charAt(i) == ch) {
                    count++;
                } else {
                    compressed.append(count).append(ch);
                    ch = result.charAt(i);
                    count = 1;
                }
            }

            compressed.append(count).append(ch); 
            result = compressed.toString();
        }

        if (result.length() > 50) {
            throw new AlgoException("Trop de caractères");
        }

        return result;
    }

    public static String unRLE(String in) throws AlgoException {
        return unRLE(in, 1);
    }

    public static String unRLE(String in, int iteration) throws AlgoException {
        if (in == null || in.isEmpty()) {
            return "";
        }

        String result = in;
        for (int iter = 0; iter < iteration; iter++) {
            StringBuilder decompressed = new StringBuilder();
            int index = 0;

            while (index < result.length()) {
                char c = result.charAt(index++);
                if (Character.isDigit(c)) {
                    int count = c - '0';
                    while (index < result.length() && Character.isDigit(result.charAt(index))) {
                        count = count * 10 + (result.charAt(index++) - '0');
                    }
                    if (index < result.length()) {
                        char ch = result.charAt(index++);
                        for (int k = 0; k < count; k++) {
                            decompressed.append(ch);
                        }
                    } else {
                        throw new AlgoException("Format RLE invalide: " + result);
                    }
                } else {
                    decompressed.append(c);
                }
            }

            result = decompressed.toString();
        }

        return result;
    }
}
