package iut.sae.algo;

/************************************************/
/*             Simplicité / Java                */
/************************************************/

public class simplicite {

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