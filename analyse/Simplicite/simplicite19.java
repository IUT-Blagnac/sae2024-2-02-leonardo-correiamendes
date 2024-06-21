package iut.sae.algo;

// 19simplicite.java
// Compile V
// Anonyme V
// Java Util V
// Fonctionne V
// Passe les tests X
// Passe tous les tests X
// Passe mes tests X
// Noté sur 10 

// Le code est très simple et compréhensible.
// Cependant il a fait qu'un seul algo sur 4 et par conséquent ne passe pas les test.
// De plus, même dans l'algo réalisé il y des problemes avec les test donc -1 point.
// Je retire 2.5 points pour chaque algo manquant.
// Note : 1.5/20
// Classement : 5eme

/************************************************/
/*             Simplicité / Java                */
/************************************************/

public class simplicite19 {

    public static String encodage_rle_simplicite(String texte) {

        String resultat = "";

        char caract = texte.charAt(0);

        int compteur = 1;

        for (int i = 1; i < texte.length(); i++) {

            if (texte.charAt(i) == caract) {

                compteur++;

                if (compteur == 9) {

                    resultat += caract + "" + compteur;

                    caract = texte.charAt(i);

                    compteur = 0;
                }
            } else {

                resultat += caract + "" + compteur;

                caract = texte.charAt(i);

                compteur = 1;
            }
        }

        if (0 < compteur) {

            resultat += caract + "" + compteur;

        }

        return resultat;
    }
}

/************************************************/
/*             Simplicité / Java                */
/************************************************/